#ifndef GAME_ICONS
#define GAME_ICONS

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

// Structure for solid rect icons.
struct solid_icon{
    SDL_Surface *surface;
    SDL_Rect *pos;
};

// Allocate and initialize a new solid rect icon structure
struct solid_icon *solid_icon_init(int x, int y, unsigned int w, unsigned int h, uint32_t rgba);

// Set 32-bit RGBA color on solid rect icon structure
_Bool solid_icon_set(struct solid_icon *dest, uint32_t rgba);

// Draw icon onto destination surface
_Bool solid_icon_draw(SDL_Surface *dest, struct solid_icon *icon);

// Free Icon
void solid_icon_free(struct solid_icon *i);

// Structure for image rect icons 
struct img_icon{
    SDL_Surface *img;
    SDL_Rect *pos;
};

// CAllocate and initialize a new image rect icon structure
struct img_icon *img_icon_init(int x, int y, unsigned w, unsigned h, const char *path);

// Set the image of icon according to given path
_Bool img_icon_set(struct img_icon *dest, const char *path);

// Draw icon onto destination surface
_Bool img_icon_draw(SDL_Surface *dest, struct img_icon *icon);

// Free icon
void img_icon_free(struct img_icon *target);

#endif