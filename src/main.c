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
SDL_Init(SDL_INIT_VIDEO);
//window
SDL_Window *window;
//surface
SDL_Surface * background,*ScreenSurface,*images[5],*text_surface;
//rectangle
SDL_Rect center,right;
//string
char chain[50]="hello world";
//vars
int menu=0,play=0,score=0;
//text color
SDL_Color textColor= { 255, 0, 0 };
//font
TTF_Font * font;
//sdl_event
SDL_Event event;
//mix Music
Mix_Music* music;
// mix chunk
Mix_Chunk * click;




//rect
center.w=0;
center.h=0;
center.x=150;
center.y=100;

//right
right.h=0;
right.w=0;
right.x=1000;
right.y=200;
///



//images
images[0]=IMG_Load("images/orange.png");
images[1]=IMG_Load("images/Pear.png");
images[2]=IMG_Load("images/pineapple.png");




//printf("enter your name : ");
//scanf("%s",chain);

window= SDL_CreateWindow("workshop exemple", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_FULLSCREEN_DESKTOP);
ScreenSurface=SDL_GetWindowSurface(window);

background=IMG_Load("images/menu.bmp");

//OPEN FONT 
TTF_Init();
font  = TTF_OpenFont("fonts/ARIAL.TTF",65);
text_surface=TTF_RenderText_Solid(font,"welcome", textColor);

//SDL Mixer
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048);

//music = Mix_LoadMUS("sounds/sound.ogg");

//Mix_VolumeMusic(100);

//Mix_PlayMusic(music,-1);

click=Mix_LoadWAV("sounds/mouse-click.ogg");
Mix_VolumeChunk(click,100);



//menu
menu:
menu=1;
 
while(menu!=0){


SDL_BlitSurface( background, NULL, ScreenSurface, NULL);

SDL_WaitEvent(&event);

//while(SDL_PollEvent(&event)){
     switch(event.type){
        case SDL_QUIT:
        menu = 0;
        goto quit;
        break;

        case SDL_KEYDOWN: 

        switch (event.key.keysym.sym){
      case SDLK_ESCAPE:
       menu=0;
       goto quit;
       break;
       }
       case SDL_MOUSEBUTTONUP:
       if (event.button.button == SDL_BUTTON_LEFT){
       if(event.button.x>202 && event.button.x<542 && event.button.y>426  && event.button.y<508 ){
         Mix_PlayChannel(-1,click,0);
           SDL_BlitSurface(images[0], NULL, ScreenSurface,&right);
       }

       }
       break;
       case SDL_MOUSEMOTION:
       if(event.motion.x>202 && event.motion.x<542 && event.motion.y>516+23  && event.motion.y<508+23+412 ){
          //Mix_PlayChannel(-1,click,0);
           SDL_BlitSurface(images[0], NULL, ScreenSurface,&right);
       }

       break;
   
   break;
   }
 //  }


SDL_BlitSurface( text_surface, NULL, ScreenSurface, NULL);
SDL_UpdateWindowSurface( window );

}







quit:
TTF_CloseFont(font);
for(int i=0;i<=3;i++){
    SDL_FreeSurface(images[i]);
}
SDL_FreeSurface(text_surface);
SDL_FreeSurface(background);
SDL_FreeSurface(ScreenSurface);
SDL_DestroyWindow(window);


    TTF_Quit();
    SDL_Quit();
   


    return 0;
}