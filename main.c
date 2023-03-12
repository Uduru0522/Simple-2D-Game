#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "icon.h"

// Set the width and height of the window
const int WIDTH = 960, HEIGHT = 540;

int main(int argc, char *argv[]){
    // Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);

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

    // Create surface to draw, assigned to the main window
    SDL_Surface *screen = SDL_GetWindowSurface(window);

    // Create an event to listen for window events
    SDL_Event event;

    // Create icon object
    struct solid_icon *i = solid_icon_init(100, 100, 100, 100);

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

        SDL_FillRect(screen, NULL, 0xFFFFFF);
        solid_icon_draw(screen, i);
        SDL_UpdateWindowSurface(window);
    }

    // Free all allocated memory and exit
    solid_icon_free(i);
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}