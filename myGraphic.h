#ifndef MYGRAPHIC_H_INCLUDED
#define MYGRAPHIC_H_INCLUDED
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include"myFunctionData.h"
void drawNotification( SDL_Renderer *renderer,TTF_Font * font );
void draw9x9(SDL_Renderer* renderer);
void draw3x3(SDL_Renderer* renderer);
void draw1x1(SDL_Renderer* renderer,int x,int y);
void drawSudoku(SDL_Renderer* renderer,int x ,int y);
void drawData(SDL_Renderer * renderer,TTF_Font * font,int *sudokuUpdate,int sudokuZeRo[9][9], int x,int y,int sudokuCheck[9][9]);
void addEvent(SDL_Renderer *renderer,TTF_Font * font,SDL_Event event,int &x,int &y,int *sudokuUpdate,int *sudokuCheck,int *sudokuResult,int *sudokuZeRo,bool  &quit);
void drawYouWin(SDL_Renderer * renderer,TTF_Font * font);
void loadImage(SDL_Renderer * renderer);
void runGame(SDL_Renderer * renderer,TTF_Font * font,bool &quit);
void addEventYouWin(SDL_Event event,SDL_Renderer * renderer,TTF_Font * font,bool &quit);
void remuseGame(SDL_Renderer * renderer,TTF_Font * font,bool &quit);
void addEventMenu(SDL_Event event,SDL_Renderer * renderer,TTF_Font * font,bool &quit,bool &quit2);
void drawMenu(SDL_Renderer * renderer,TTF_Font * font);
void drawHightLine(SDL_Renderer* renderer,int x,int y);
#endif // MYGRAPHIC_H_INCLUDED
