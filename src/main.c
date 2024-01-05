#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "functions.h"
#include <unistd.h>


#define SCREEN_WIDTH 1920 
#define SCREEN_HEIGHT 1080


int main(int argc, char** argv){
SDL_Init(SDL_INIT_VIDEO);
//window
SDL_Window *window;
//surface
<<<<<<< HEAD
SDL_Surface * background,*ScreenSurface,*images[5],*text_button[2],*menu_images[10],*menu_sound,*play_images[10];
//rectangle
SDL_Rect center,right,menu_rect[2],sound_button_rect,play_rect,numbers_rect;
=======
SDL_Surface * background,*ScreenSurface,*text_surface,*menu_images[3],*menu_buttons[2],*play_image,*play_numbers;
//rectangle
SDL_Rect center,right,menu_rect,menu_buttons_rect[2],numbers_rect;
>>>>>>> 4dcff90f667309cd38a464dad0ce7ee521af1919
//string
char chain[50]="hello world",play_str[100];
//vars
<<<<<<< HEAD
int menu=0,play=0,T[20],n=10;
=======
int menu=0,play=0,T[10]={9,8,7,6,5,4,3,2,1,0},n=10;
//chars
char T_str[30];
>>>>>>> 4dcff90f667309cd38a464dad0ce7ee521af1919
//text color
SDL_Color textColor= { 20, 45, 73 };
//font
TTF_Font * font,*font_bold;
//sdl_event
SDL_Event event;
//mix Music
Mix_Music* music;
// mix chunk
Mix_Chunk * click,*swap_sound,*hover_sound;
//bool sound
bool music_on=true;




<<<<<<< HEAD
//rect
center.w=0;
center.h=0;
center.x=700;
center.y=200;

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
//menu images
//sound icon
menu_images[0]=IMG_Load("images/sound_button/sound.png");
menu_images[1]=IMG_Load("images/sound_button/sound_stop.png");
// sound rect button
sound_button_rect.x=1820;
sound_button_rect.y=960;
//menu image
menu_images[2]=IMG_Load("images/menu.png");
//play_images[3] done

//sound image
menu_sound=IMG_Load("images/sound_button/sound.png");
//menu_rect buttons
//play button 
menu_rect[0].x=890;
menu_rect[0].y=530;
//quit button
menu_rect[1].x=890;
menu_rect[1].y=720;

//play page
play_images[0]=IMG_Load("images/play/play_back.png");
//play rect

play_rect.x=290;
play_rect.y=440;


//numbers_rect
numbers_rect.x=305;
numbers_rect.y=450;
//printf("enter your name : ");
//scanf("%s",chain);

window= SDL_CreateWindow("workshop exemple", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_FULLSCREEN_DESKTOP);
ScreenSurface=SDL_GetWindowSurface(window);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
background=IMG_Load("images/menu2.png");
=======

window= SDL_CreateWindow("workshop exemple", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_FULLSCREEN_DESKTOP);
ScreenSurface=SDL_GetWindowSurface(window);

background=IMG_Load("images/menu2.png");
//menu images
menu_images[0]=IMG_Load("images/menu.png");
//play image
play_image=IMG_Load("images/play/play_back.png");
>>>>>>> 4dcff90f667309cd38a464dad0ce7ee521af1919

//menu rect
menu_rect.x=680;
menu_rect.y=200;
//OPEN FONT 
TTF_Init();
font  = TTF_OpenFont("fonts/ARIAL.TTF",65);
<<<<<<< HEAD
font_bold=TTF_OpenFont("fonts/OpenSans-Bold.ttf",170);
text_button[0]=TTF_RenderText_Solid(font,"PLAY", textColor);
text_button[1]=TTF_RenderText_Solid(font,"QUIT", textColor);
//SDL Mixer
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048);

music = Mix_LoadMUS("sounds/menu.ogg");
Mix_VolumeMusic(40);




click=Mix_LoadWAV("sounds/hover_button.ogg");
swap_sound=Mix_LoadWAV("sounds/swap_sound.ogg");
hover_sound=Mix_LoadWAV("sounds/hover_SOUND.ogg");
Mix_VolumeChunk(click,100);
Mix_PlayMusic(music,0);
//menu
menu:
menu=1;
int hover=1;
=======
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
>>>>>>> 4dcff90f667309cd38a464dad0ce7ee521af1919
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
<<<<<<< HEAD

       if(event.button.x>1810 && event.button.x<1902 && event.button.y>984  && event.button.y<1072 ){
        
        if(music_on){
          menu_sound=menu_images[1];
          Mix_PauseMusic();
          music_on=false;
        }
        else {
          menu_sound=menu_images[0];
          Mix_ResumeMusic();
          music_on=true;
        }
        Mix_PlayChannel(-1,click,0);
         
=======
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
>>>>>>> 4dcff90f667309cd38a464dad0ce7ee521af1919
       }

         else if(event.button.x>782 && event.button.x<1169 && event.button.y>505  && event.button.y<620 ){
          Mix_PlayChannel(-1,click,0);
          menu=0;
          goto play; 
       }
       else if (event.button.x>788 && event.button.x<1169 && event.button.y>700  && event.motion.y<820 ){
        Mix_PlayChannel(-1,click,0);
        goto quit;

       }


       }
       break;
       case SDL_MOUSEMOTION:
<<<<<<< HEAD
       
       if(event.motion.x>782 && event.motion.x<1169 && event.motion.y>505  && event.motion.y<620 ){
        if(hover){
          Mix_PlayChannel(-1,hover_sound,0);
          hover=0;
        }
          SDL_Color hover_color= { 255, 255, 255 };
          text_button[0]=TTF_RenderText_Solid(font,"PLAY", hover_color);
=======
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
>>>>>>> 4dcff90f667309cd38a464dad0ce7ee521af1919
       }
       else if (event.motion.x>788 && event.motion.x<1169 && event.motion.y>700  && event.motion.y<820 ){

        if(hover){
          Mix_PlayChannel(-1,hover_sound,0);
          hover=0;
        }
        SDL_Color hover_color= { 255, 255, 255 };
        text_button[1]=TTF_RenderText_Solid(font,"QUIT", hover_color);
       }
       else {
        if(!hover)hover=1;
       
        text_button[0]=TTF_RenderText_Solid(font,"PLAY", textColor);
        text_button[1]=TTF_RenderText_Solid(font,"QUIT", textColor);
       }
      

       break;
   
   break;
   }
   }

<<<<<<< HEAD
SDL_BlitSurface(menu_sound, NULL, ScreenSurface, &sound_button_rect);
SDL_BlitSurface(menu_images[2], NULL, ScreenSurface, &center);
SDL_BlitSurface( text_button[0], NULL, ScreenSurface,&menu_rect[0]);
SDL_BlitSurface( text_button[1], NULL, ScreenSurface,&menu_rect[1]);
=======

>>>>>>> 4dcff90f667309cd38a464dad0ce7ee521af1919
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

play:
play=1;
int onetime=1;
 for (int i = 9; i >= 0; --i) {
        T[9 - i] = i;
    }
convertIntToCharWithSpaces(T,play_str,n,1);
play_images[3]=TTF_RenderText_Solid(font_bold,play_str,textColor);
//SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, play_images[0]);
//SDL_Texture* texture_text=SDL_CreateTextureFromSurface(renderer, play_images[3]);
SDL_BlitSurface( play_images[0], NULL, ScreenSurface,NULL);
SDL_BlitSurface( play_images[3], NULL, ScreenSurface,&play_rect);
while(play){
  SDL_UpdateWindowSurface(window);
if(onetime==1){
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (T[j] > T[j + 1]) {
                // Swap arr[j] and arr[j + 1] int
                  swap(&T[j], &T[j + 1]);
                  while(SDL_PollEvent(&event)){
     switch(event.type){
        case SDL_QUIT:
        menu = 0;
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
              convertIntToCharWithSpaces(T,play_str,n,1);
                SDL_FreeSurface(play_images[3]);
                play_images[3]=TTF_RenderText_Solid(font_bold,play_str,textColor);
                SDL_BlitSurface( play_images[0], NULL, ScreenSurface,NULL);
                SDL_BlitSurface( play_images[3], NULL, ScreenSurface,&play_rect);
                Mix_PlayChannel(-1,swap_sound,0);
                SDL_Delay(500);
               SDL_UpdateWindowSurface(window);

               
            }
            
        }
    }
    onetime=0;
}




//SDL_WaitEvent(&event);

while(SDL_PollEvent(&event)){
     switch(event.type){
        case SDL_QUIT:
        menu = 0;
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

int j;

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
<<<<<<< HEAD
for(int i=0;i<=3;i++){
    SDL_FreeSurface(images[i]);
}
for(int i=0;i<=2;i++){
  SDL_FreeSurface(text_button[i]);
}
SDL_FreeSurface(menu_sound);
=======
SDL_FreeSurface(text_surface);
>>>>>>> 4dcff90f667309cd38a464dad0ce7ee521af1919
SDL_FreeSurface(background);
SDL_FreeSurface(ScreenSurface);
SDL_DestroyWindow(window);


    TTF_Quit();
    SDL_Quit();
   


    return 0;
}