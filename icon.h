#ifndef GAME_ICONS
#define GAME_ICONS

#include <SDL2/SDL.h>
#include <stdbool.h>

enum icon_type{
    ICON_RGBA = 1,  // Solid color, specified by 32-bit value
    ICON_IMG = 2,   // Image (.png / .jpg), specified by path
};

// Structure of surface icons
struct icon{
    enum icon_type type;
    SDL_Surface *surface;
    SDL_Rect *pos;
};

// Allocate and initialize a new icon according to specified type
struct icon *icon_init(int x, int y, unsigned int w, unsigned int h, enum icon_type type);

// Draw icon onto specified parent surface
_Bool icon_draw(SDL_Surface *dest, struct icon *target);

// Set image / color of icon
_Bool icon_set(struct icon *target, uint32_t rgba, const char *path);

// Free icons
void icon_free(struct icon *target);

#endif