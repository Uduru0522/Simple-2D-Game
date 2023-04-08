#include <stdio.h>
#include <stdbool.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.h"

struct sprite *sprite_init(int x, int y, unsigned int w, unsigned int h)
{
    // Allocate memory for sprite
    struct sprite *s = malloc(sizeof(struct sprite));
    if(s == NULL){
        printf("Error in sprite_init(): Failed to allocate memory for sprite]\n");
        return NULL;
    }

    // Initialize SDL_texture
    s->texture = NULL;

    // Allocate memory for SDL_Rect
    s->pos = malloc(sizeof(SDL_Rect));
    if(s->pos == NULL){
        printf("Error in sprite_init(): Failed to allocate memory for rect\n");
        free(s);
        return NULL;
    }

    // Set position information
    s->pos->x = x;
    s->pos->y = y;
    s->pos->w = w;
    s->pos->h = h;

    // Initialize rotation angle
    s->angle = 0;

    return s;
}

_Bool sprite_set_renderer(struct sprite *target, SDL_Renderer *parent)
{   
    // Check if sprite is initialized
    if(target == NULL){
        printf("Error in sprite_set_renderer(): Sprite is not intialized\n");
        return false;
    }

    // Check if renderer is created
    if(parent == NULL){
        printf("Error in sprite_set_renderer(): Host renderer does not exist\n");
        return false;
    }

    // Set renderer of sprite
    target->renderer = parent;
    return true;
}

_Bool sprite_set_texture(struct sprite *target, const char *path)
{
    // Remove texture if already set
    if(target->texture != NULL){
        SDL_DestroyTexture(target->texture);
        target->texture = NULL;
    }

    // Load image to temp variable
    SDL_Surface *temp = IMG_Load(path);
    if(temp == NULL){
        printf("Error in sprite_set_texture(): Failed to load image\n");
        return false;
    }

    // Create texture from image
    target->texture = SDL_CreateTextureFromSurface(target->renderer, temp);
    SDL_FreeSurface(temp);
    return true;
}

_Bool sprite_draw(struct sprite *target)
{
    SPRITE_CHECK_USEABLE(target, return false);

    // Render texture onto renderer
    SDL_Point *pivot = NULL;
    SDL_RenderCopyEx(target->renderer, target->texture,
                     NULL, target->pos, target->angle, pivot, SDL_FLIP_NONE);
    return true;
}

void sprite_set_pos(struct sprite *target, int x, int y){
    SPRITE_CHECK_USEABLE(target, return);

    // Set postion of sprite
    target->pos->x = x;
    target->pos->y = y;
}

void sprite_set_size(struct sprite *target, unsigned int w, unsigned int h)
{   
    SPRITE_CHECK_USEABLE(target, return);

    // Set dimension of sprite
    target->pos->w = w;
    target->pos->h = h;
    return;
}

_Bool sprite_set_deg(struct sprite *target, double angle)
{
    SPRITE_CHECK_USEABLE(target, return false);

    // Increment rotation value
    target->angle += angle;
    if(target->angle > 360.0){
        target->angle -= 360;
    }
    return true;
}

void sprite_free(struct sprite *target)
{
    SDL_DestroyTexture(target->texture);
    free(target);
    return;
}