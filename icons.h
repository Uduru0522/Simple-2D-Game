#ifndef GAME_ICONS
#define GAME_ICONS

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

// Structure for solid rect icons
struct solid_icon{
    SDL_Surface *surface;
    SDL_Rect *pos;
};

// Create and initialize a new solid rect icon structure.
struct solid_icon *solid_icon_init(int x, int y, unsigned int w, unsigned int h, uint32_t rgba);

// Set 32-bit RGBA color on solid rect icon structure
_Bool solid_icon_set(struct solid_icon *dest, uint32_t rgba);

// Draw icon onto destination surface
_Bool solid_icon_draw(SDL_Surface *dest, struct solid_icon *icon);

// Free Icon
void solid_icon_free(struct solid_icon *i);

#endif