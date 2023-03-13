#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "icon.h"

struct icon *icon_init(int x, int y, unsigned int w, unsigned int h, enum icon_type type)
{
    // Allocate memory for icon
    struct icon *icon = malloc(sizeof(struct icon));
    if(icon == NULL){
        printf("Error in icon_init(): Failed to allocate struct icon\n");
        return NULL;
    }

    // Set type of icon according to enum icon_type
    icon->type = type;

    // Allocate memory for SDL_Rect
    icon->pos = malloc(sizeof(SDL_Rect));
    if(icon->pos == NULL){
        printf("Error in `icon_init()`: Failed allocating SDL_Rect\n");
        free(icon);
        return NULL;
    }
    
    // Initialize surface
    icon->surface = NULL;

    // Set position information
    icon->pos->x = x;
    icon->pos->y = y;
    icon->pos->w = w;
    icon->pos->h = h; 

    return icon;
}

_Bool icon_set(struct icon *target, uint32_t rgba, const char *path)
{
    // Check if icon is allocated
    if(target == NULL){
        printf("Error in icon_set_rgba(): icon is not allocated\n");
        return false;
    }

    // Set surface according to type
    switch(target->type){
    case ICON_RGBA:
        // Check if surface is allocated
        target->surface = SDL_CreateRGBSurface(0, target->pos->w, target->pos->h,
                                               32, 0, 0, 0, 0);

        // Fill in color
        SDL_FillRect(target->surface, NULL, rgba);
        break;
    case ICON_IMG:
        // Free loaded image if is already lodaded
        if(target->surface != NULL){
            SDL_FreeSurface(target->surface);
        }

        // Load image to surface
        target->surface = IMG_Load(path);
        if(target->surface == NULL){
            printf("Error in icon_set(): Failed to load image\n");
            return false;
        }
        break;
    }

    return true;
}

_Bool icon_draw(SDL_Surface *dest, struct icon *target)
{
    if(target->surface == NULL){
        printf("Error in `img_icon_draw(): source surface is NULL\n");
        return false;
    }
    
    SDL_BlitSurface(target->surface, NULL, dest, target->pos);
    return true;
}

void icon_free(struct icon *target){
    SDL_FreeSurface(target->surface);
    free(target->pos);
    free(target);
    return;
}