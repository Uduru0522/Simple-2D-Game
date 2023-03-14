#ifndef GAME_SPRITE
#define GAME_SPRITE

#include <stdbool.h>
#include <SDL2/SDL.h>

// Structure of renderer & texture based sprite
struct sprite{
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect *pos;
};

// Initialize structure of sprite
struct sprite *sprite_init(int x, int y, unsigned int w, unsigned int h);

// Set renderer of sprite
_Bool sprite_set_renderer(struct sprite *target, SDL_Renderer *parent);

// Set texture of sprite
_Bool sprite_set_texture(struct sprite *target, const char *path);

// Draw sprite onto renderer
_Bool sprite_draw(struct sprite *target);

// Free sprite
void sprite_free(struct sprite *target);

#endif