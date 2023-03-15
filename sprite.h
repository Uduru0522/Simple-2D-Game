#ifndef GAME_SPRITE
#define GAME_SPRITE

#include <stdbool.h>
#include <SDL2/SDL.h>

// Structure of renderer & texture based sprite
struct sprite{
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect *pos;
    double angle;
};

#define SPRITE_CHECK_USEABLE(sprite, ret) do{ \
        if(sprite == NULL){ \
            printf("Error in %s(): Sprite is not allocated\n", __func__); \
            ret; \
        } \
        if(sprite->texture == NULL){ \
            printf("Error in %s(): Texture is not set\n", __func__); \
            ret; \
        } \
    }while(false) \

// Initialize structure of sprite
struct sprite *sprite_init(int x, int y, unsigned int w, unsigned int h);

// Set renderer of sprite
_Bool sprite_set_renderer(struct sprite *target, SDL_Renderer *parent);

// Set texture of sprite
_Bool sprite_set_texture(struct sprite *target, const char *path);

// Draw sprite onto renderer
_Bool sprite_draw(struct sprite *target);

// Set position of sprite
void sprite_set_pos(struct sprite *target, int x, int y);

// Set dimension of sprite
void sprite_set_size(struct sprite *target, unsigned int w, unsigned int h);

// Set rotation angle ofprite
_Bool sprite_set_deg(struct sprite *target, double angle);

// Free sprite
void sprite_free(struct sprite *target);

#endif