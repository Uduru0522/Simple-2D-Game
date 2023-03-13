#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "icon.h"

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

    // Create surface to draw, assigned to the main window
    SDL_Surface *screen = SDL_GetWindowSurface(window);
    SDL_FillRect(screen, NULL, 0xFFFFFF);

    // Create an event to listen for window events
    SDL_Event event;

    // Array for color rotaion
    int idx = 0;
    uint32_t colors[] = {
        0x958874, 0x993955, 0x0E3B43, 0xDAF5FF, 0x335145
    };

    // Create solid icon
    struct icon *i = icon_init(100, 100, 100, 100, ICON_RGBA);

    // Create image icon and draw onto screen
    struct icon *img = icon_init(200, 200, 576, 384, ICON_IMG);
    icon_set(img, 0, ".\\resources\\chara.png");
    icon_draw(screen, img);

    printf("Ready to loop!\n");

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

        SDL_UpdateWindowSurface(window);
        SDL_Delay(500);
        icon_set(i, colors[idx = (idx + 1) % 5], NULL);
        icon_draw(screen, i);
    }

    // Free all allocated memory and exit
    icon_free(i);
    icon_free(img);
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);

    // Quit SDL and IMG system
    IMG_Quit();
    SDL_Quit();
    return 0;
}