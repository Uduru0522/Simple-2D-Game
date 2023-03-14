#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.h"

// Set the width and height of the window
const int WIDTH = 960, HEIGHT = 540;

int main(int argc, char *argv[]){
    // Initialize SDL / SDL_Image for .png and .jpg
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    // Create a resizable, maximized, and high-DPI-aware main window
    SDL_Window *window = SDL_CreateWindow("Hello World!", 
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                          WIDTH, HEIGHT,
                                          SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_ALLOW_HIGHDPI);

    // Check if the window was created successfully
    if(window == NULL){
        printf("Creating window failed: %s\n", SDL_GetError());
        return -1;
    }

    // Create renderer for full window
    SDL_Renderer *screen = SDL_CreateRenderer(window, -1, 0);

    // Create an event to listen for window events
    SDL_Event event;

    // Create sprite and set renderer
    struct sprite *s = sprite_init(200, 200, 1152, 768);
    sprite_set_renderer(s, screen);
    sprite_set_texture(s, ".\\resources\\chara.png");

    // Keep the program running until the user closes the window
    _Bool running = true;
    while(running){
        // Poll and process every events from the event queue
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    continue;
            }
        }

        sprite_draw(s);
        SDL_RenderPresent(screen);
        SDL_Delay(500);
    }

    // Free all allocated memory and exit
    SDL_DestroyRenderer(screen);
    SDL_DestroyWindow(window);

    // Quit SDL and IMG system
    IMG_Quit();
    SDL_Quit();
    return 0;
}