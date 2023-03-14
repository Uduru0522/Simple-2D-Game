#include <stdio.h>
#include <stdbool.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.h"

struct sprite *sprite_init(int x, int y, unsigned int w, unsigned int h)
{
    // Allocate memory for sprite
    struct sprite *sprite = malloc(sizeof(struct sprite));
    if(sprite == NULL){
        printf("Error in sprite_init(): Failed to allocate memory for sprite]\n");
        return NULL;
    }

    // Initialize SDL_texture
    sprite->texture = NULL;

    // Allocate memory for SDL_Rect
    sprite->pos = malloc(sizeof(SDL_Rect));
    if(sprite->pos == NULL){
        printf("Error in sprite_init(): Failed to allocate memory for rect\n");
        free(sprite);
        return NULL;
    }

    // Set position information
    sprite->pos->x = x;
    sprite->pos->y = y;
    sprite->pos->w = w;
    sprite->pos->h = h;

    return sprite;
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
    // Check if texture is set
    if(target->texture == NULL){
        printf("Error in sprite_draw(): Texture not set\n");
        return false;
    }

    // Render texture onto renderer
    SDL_RenderCopy(target->renderer, target->texture, NULL, target->pos);
}

void sprite_free(struct sprite *target)
{
    SDL_DestroyTexture(target->texture);
    free(target);
    return;
}