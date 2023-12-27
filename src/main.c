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
SDL_Surface * background,*ScreenSurface,*text_surface,*menu_images[3],*menu_buttons[2],*play_image,*play_numbers;
//rectangle
SDL_Rect center,right,menu_rect,menu_buttons_rect[2],numbers_rect;
//string
char chain[50]="hello world";
//vars
int menu=0,play=0,T[10]={9,8,7,6,5,4,3,2,1,0},n=10;
//chars
char T_str[30];
//text color
SDL_Color textColor= { 20, 45, 73 };
//font
TTF_Font * font;
//sdl_event
SDL_Event event;
//mix Music
Mix_Music* music;
// mix chunk
Mix_Chunk * click;





window= SDL_CreateWindow("workshop exemple", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_FULLSCREEN_DESKTOP);
ScreenSurface=SDL_GetWindowSurface(window);

background=IMG_Load("images/menu2.png");
//menu images
menu_images[0]=IMG_Load("images/menu.png");
//play image
play_image=IMG_Load("images/play/play_back.png");

//menu rect
menu_rect.x=680;
menu_rect.y=200;
//OPEN FONT 
TTF_Init();
font  = TTF_OpenFont("fonts/ARIAL.TTF",65);
TTF_Font * font2=TTF_OpenFont("fonts/OpenSans-Bold.ttf",170);

menu_buttons[0]=TTF_RenderText_Solid(font,"START",textColor);
menu_buttons[1]=TTF_RenderText_Solid(font,"QUIT",textColor);

//menu_buttons_rect
menu_buttons_rect[0].x=860;
menu_buttons_rect[0].y=520;
menu_buttons_rect[1].x=860;
menu_buttons_rect[1].y=720;


//numbers_rect
numbers_rect.x=305;
numbers_rect.y=450;

//SDL Mixer
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048);
click=Mix_LoadWAV("sounds/hover_button.ogg");
Mix_VolumeChunk(click,100);

//menu
menu:
menu=1;
//Mix_PlayMusic(music,0);
while(menu!=0){
SDL_BlitSurface( background, NULL, ScreenSurface, NULL);
SDL_BlitSurface( menu_images[0], NULL, ScreenSurface, &menu_rect);
SDL_BlitSurface( menu_buttons[0], NULL, ScreenSurface, &menu_buttons_rect[0]);
SDL_BlitSurface( menu_buttons[1], NULL, ScreenSurface, &menu_buttons_rect[1]);
while(SDL_PollEvent(&event)){
  SDL_Color hover_color= { 255, 255, 255 };
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
       if(event.button.x>782 && event.button.x<1169 && event.button.y>505  && event.button.y<620){
        //play
        //menu=0;
        Mix_PlayChannel(-1,click,0);
        goto play;

       }
       else if (event.button.x>788 && event.button.x<1169 && event.button.y>700  && event.button.y<820){
        //quit 
        //menu=0;
        Mix_PlayChannel(-1,click,0);
        goto quit;
       }

       }
       break;
       case SDL_MOUSEMOTION:
       if(event.motion.x>782 && event.motion.x<1169 && event.motion.y>505  && event.motion.y<620){
        //play
        SDL_FreeSurface(menu_buttons[0]);
          menu_buttons[0]=TTF_RenderText_Solid(font,"PLAY", hover_color);
       }
       else if(event.motion.x>788 && event.motion.x<1169 && event.motion.y>700  && event.motion.y<820 ){
        //quit
         SDL_FreeSurface(menu_buttons[1]);
          menu_buttons[1]=TTF_RenderText_Solid(font,"QUIT", hover_color);
         
       }
       else {
        SDL_FreeSurface(menu_buttons[1]);
        SDL_FreeSurface(menu_buttons[0]);
        menu_buttons[0]=TTF_RenderText_Solid(font,"PLAY", textColor);
        menu_buttons[1]=TTF_RenderText_Solid(font,"QUIT", textColor);
       }

       break;
   
   break;
   }
   }


SDL_UpdateWindowSurface( window );

}


play:
play=1;
 //for (int i = 9; i >= 0; --i) {
 //       T[9 - i] = i;
//} 
    //9/8/7/6/5/4/3/2/1/0
    convertIntToCharWithSpaces(T,T_str,n,1);
play_numbers=TTF_RenderText_Solid(font2,T_str,textColor);

while(play){


SDL_BlitSurface(play_image,NULL,ScreenSurface,NULL);
SDL_BlitSurface(play_numbers,NULL,ScreenSurface,&numbers_rect);
SDL_UpdateWindowSurface( window );


for (int i = 0; i < n - 1; i++) {
            
        for (int j = 0; j < n - i - 1; j++) {
            if (T[j] > T[j + 1]) {
              while(SDL_PollEvent(&event)){
     switch(event.type){
        case SDL_QUIT:
        play = 0;
        goto quit;
        break;

        case SDL_KEYDOWN: 

        switch (event.key.keysym.sym){
      case SDLK_ESCAPE:
       play=0;
       goto menu;
       break;
       }
   break;
   }
   }
                // Swap arr[j] and arr[j + 1] int
                  swap(&T[j], &T[j + 1]);
                  convertIntToCharWithSpaces(T,T_str,n,1);
                  SDL_FreeSurface(play_numbers);
                  play_numbers=TTF_RenderText_Solid(font2,T_str,textColor);
         SDL_BlitSurface(play_image,NULL,ScreenSurface,NULL);
           SDL_BlitSurface(play_numbers,NULL,ScreenSurface,&numbers_rect);
                  SDL_UpdateWindowSurface( window );
                  SDL_Delay(1000);
            
        }
    }
}



while(SDL_PollEvent(&event)){
     switch(event.type){
        case SDL_QUIT:
        play = 0;
        goto quit;
        break;

        case SDL_KEYDOWN: 

        switch (event.key.keysym.sym){
      case SDLK_ESCAPE:
       play=0;
       goto menu;
       break;
       }
   break;
   }
   }


}



quit:
TTF_CloseFont(font);
SDL_FreeSurface(text_surface);
SDL_FreeSurface(background);
SDL_FreeSurface(ScreenSurface);
SDL_DestroyWindow(window);


    TTF_Quit();
    SDL_Quit();
   


    return 0;
}