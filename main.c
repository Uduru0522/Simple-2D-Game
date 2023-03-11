#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

const int WIDTH = 960, HEIGHT = 540;

int main(int argc, char *argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Hello World!", 
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                          WIDTH, HEIGHT,
                                          SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_ALLOW_HIGHDPI);

    if(window == NULL){
        printf("Creating window failed: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Event window_event;
    while(true){
        if(SDL_PollEvent(&window_event)){
            if(window_event.type == SDL_QUIT){
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}