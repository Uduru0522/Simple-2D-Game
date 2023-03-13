#include "icons.h"
#include <stdio.h>
#include <stdbool.h>

struct solid_icon *solid_icon_init(int x, int y, unsigned int w, unsigned int h, uint32_t rgba)
{
    // Allocate memory for icon
    struct solid_icon *new = malloc(sizeof(struct solid_icon));
    if(new == NULL){
        printf("Error: Failed allocation solid rect icon\n");
        return NULL;
    }

    // Initialize Variables within the structure
    new->surface = NULL;
    new->pos = NULL;

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
    solid_icon_set(new, rgba);
    return new;
}

_Bool solid_icon_set(struct solid_icon *dest, uint32_t rgba)
{
    // Check if icon is initialized
    if(dest == NULL || dest->surface == NULL || dest->pos == NULL){
        printf("Error: solid_icon is not initialized\n");
        return false;
    }

    SDL_FillRect(dest->surface, NULL, rgba);
}

_Bool solid_icon_draw(SDL_Surface *dest, struct solid_icon *icon)
{
    if(icon->surface == NULL){
        printf("Error: source surface is NULL\n");
        return false;
    }
    
    SDL_BlitSurface(icon->surface, NULL, dest, icon->pos);
    return true;
}

void solid_icon_free(struct solid_icon *target){
    SDL_FreeSurface(target->surface);
    free(target->pos);
    free(target);
    return;
}

struct img_icon *img_icon_init(int x, int y, unsigned w, unsigned h, const char *path)
{
    // Allocate memory for icon
    struct img_icon *new = malloc(sizeof(struct img_icon));
    if(new == NULL){
        printf("Error: Failed allocation image rect icon\n");
        return NULL;
    }

    // Initialize variables within the structure
    new->img = NULL;
    new->pos = NULL;

    // Set value for x, y, w, h if set to default(0)
    x = x ? x : 100;
    y = y ? y : 100;
    w = w ? w : 100;
    h = h ? h : 100;

    // Allocate memory for SDL_Rect
    new->pos = malloc(sizeof(SDL_Rect));
    if(new->pos == NULL){
        printf("Error in `img_icon_init()`: Failed allocating SDL_Rect\n");
        free(new);
        return NULL;
    }

    // Allocate and load image
    if(!img_icon_set(new, path)){
        printf("Error in `img_icon_init()`: Failed to load image to surface\n");
        free(new->pos);
        free(new);
        return NULL;
    }

    // Set member vars for rect
    new->pos->x = x;
    new->pos->y = y;
    new->pos->w = w;
    new->pos->h = h;
    return new;   
}

_Bool img_icon_set(struct img_icon *dest, const char *path){
    // Free loaded image if is already lodaded
    if(dest->img != NULL){
        SDL_FreeSurface(dest->img);
    }

    // Load image to surface
    dest->img = IMG_Load(path);
    if(dest->img == NULL){
        return false;
    }

    return true;
}   

_Bool img_icon_draw(SDL_Surface *dest, struct img_icon *icon)
{
    if(icon->img == NULL){
        printf("Error in `img_icon_draw(): source surface is NULL\n");
        return false;
    }
    
    SDL_BlitSurface(icon->img, NULL, dest, icon->pos);
    return true;
}

void img_icon_free(struct img_icon *target){
    SDL_FreeSurface(target->img);
    free(target->pos);
    free(target);
    return;
}