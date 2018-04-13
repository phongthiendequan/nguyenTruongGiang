#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include"myGraphic.h"
#include"myFunctionData.h"
#include<iostream>
using namespace std;
int main(int argc, char ** argv)
{

 bool quit= false;
 bool quit2=false;
 SDL_Event event;
 SDL_Init(SDL_INIT_VIDEO);
 TTF_Init();

 SDL_Window * window = SDL_CreateWindow("SUDOKU",
  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
  600, 0);
 SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

 TTF_Font * font = TTF_OpenFont("arial.ttf", 25);

 while(!quit||!quit2)
 {
  SDL_WaitEvent(&event);


  switch (event.type)
  {
  case SDL_QUIT:
  quit = true;
  quit2= true;
   break;
  }

     loadImage(renderer);
     drawMenu(renderer,font);
     addEventMenu(event,renderer,font,quit,quit2);
     cout<<"th"<<endl;
     SDL_RenderPresent(renderer);
     SDL_RenderClear(renderer);
 }

 TTF_CloseFont(font);

 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(window);
 TTF_Quit();
 SDL_Quit();

 return 0;
}

