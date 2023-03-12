#include "icons.h"
#include <stdio.h>
#include <stdbool.h>

// Create and initialize a new icon structure.
struct solid_icon *solid_icon_init(int x, int y, unsigned int w, unsigned int h)
{
    // Allocate memory for icon
    struct solid_icon *new = malloc(sizeof(struct solid_icon));
    if(new == NULL){
        printf("Error: Failed allocation solid rect icon\n");
        return NULL;
    }

    // Set value for x, y, w, h if set to default
    x = x ? x : 100;
    y = y ? y : 100;
    w = w ? w : 100;
    h = h ? h : 100;

    // Allocate memory for SDL_Rect
    new->pos = malloc(sizeof(SDL_Rect));
    if(new->pos == NULL){
        printf("Error: Failed allocating SDL_Rect\n");
        free(new);
        return NULL;
    }

    // Allocate new solid SDL_Surface
    new->surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
    if(new->surface == NULL){
        printf("Error: %s\n", SDL_GetError());
        free(new->pos);
        free(new);
        return NULL;
    }

    // Set member vars for rect
    new->pos->x = x;
    new->pos->y = y;
    new->pos->w = w;
    new->pos->h = h;

    // Fill color in RGB Surface
    SDL_FillRect(new->surface, NULL, 0x958874);

    return new;
}

_Bool solid_icon_draw(SDL_Surface *dest, struct solid_icon *icon)
{
    if(icon->surface != NULL){
        SDL_BlitSurface(icon->surface, NULL, dest, icon->pos);
    }
    else{
        printf("Error: source surface is NULL\n");
        return false;
    }

    return true;
}

void solid_icon_free(struct solid_icon *target){
    SDL_FreeSurface(target->surface);
    free(target->pos);
    free(target);
    return;
}