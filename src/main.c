#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "functions.h"



#define SCREEN_WIDTH 1920 
#define SCREEN_HEIGHT 1080

int main(int argc, char** argv){
SDL_Window *window;
SDL_Renderer *renderer;

SDL_Init(SDL_INIT_VIDEO);

window= SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_FULLSCREEN_DESKTOP);

renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//red
SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
SDL_RenderClear(renderer);
SDL_RenderPresent(renderer);
SDL_Delay(5000);
//green
 SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
 SDL_RenderClear(renderer);
 SDL_RenderPresent(renderer);
SDL_Delay(5000);



    SDL_Quit();
    return 0;
}