#ifndef GAME_ICONS
#define GAME_ICONS

#include <SDL2/SDL.h>
#include <stdbool.h>

// Structure for rect icons
struct solid_icon{
    SDL_Surface *surface;
    SDL_Rect *pos;
};

// Create and initialize a new solid rect icon structure.
struct solid_icon *solid_icon_init(int x, int y, unsigned int w, unsigned int h);
_Bool solid_icon_draw(SDL_Surface *dest, struct solid_icon *icon);
void solid_icon_free(struct solid_icon *i);

#endif