#include"myGraphic.h"
#include"myFunctionData.h"
using namespace std;
void addEventYouWin(SDL_Event event,SDL_Renderer * renderer,TTF_Font * font,bool &quit);
void drawNotification( SDL_Renderer *renderer,TTF_Font * font )
{
    int texW, texH;
   SDL_Surface  *surface = TTF_RenderText_Solid(font,"OH!YOU ARE STUPID", {189,107,9});
   SDL_Texture  *texture = SDL_CreateTextureFromSurface(renderer,surface);
   SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
   SDL_Rect dstrect = {100,490, texW, texH };
   SDL_RenderCopy(renderer, texture,NULL, &dstrect);
   SDL_DestroyTexture(texture);
   SDL_FreeSurface(surface);

}
void drawHightLine(SDL_Renderer* renderer,int x,int y)
{
       SDL_SetRenderDrawColor(renderer, 128, 128, 128,7);
       SDL_Rect colRest{x,100,40,360};
       SDL_Rect rowRest{100,y,360,40};
       SDL_RenderFillRect ( renderer , &colRest );
       SDL_RenderFillRect ( renderer , &rowRest );

        //SDL_RenderDrawLine (renderer, 100, x, x, 460);//ke doc
        //

}
void draw9x9(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 80, 0, 255, 0);
    for(int i=100; i<=460; i+=40)
    {
        SDL_RenderDrawLine(renderer, i, 100, i, 460);//ke doc
        SDL_RenderDrawLine(renderer, 100, i, 460, i);//ke ngang
    }
}
// ve khung 9 x9
void draw3x3(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 193, 42, 29, 7);
    for(int i=100; i<=460; i+=120)
    {
        SDL_RenderDrawLine(renderer, i, 100, i, 460); //ke doc
        SDL_RenderDrawLine(renderer, 100, i, 460, i);//ke ngang
    }

}
//ve khu vuc 3x3
void draw1x1(SDL_Renderer* renderer,int x,int y)
{

    SDL_SetRenderDrawColor(renderer, 249, 204, 118, 0);
    SDL_RenderDrawLine(renderer, x, y, x+40,y );//ke doc
    SDL_RenderDrawLine(renderer, x+40, y, x+40, y+40);
    SDL_RenderDrawLine(renderer, x+40, y+40, x,y+40 );//ke doc
    SDL_RenderDrawLine(renderer, x, y+40, x, y);//ke ngang//ke ngang
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

}
void drawSudoku(SDL_Renderer* renderer,int x,int y)
{   drawHightLine(renderer, x, y);
    draw9x9(renderer);
    draw3x3(renderer);
     draw1x1(renderer,x,y);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void drawData(SDL_Renderer * renderer,TTF_Font * font,int *sudokuUpdate,int sudokuZeRo[9][9], int x,int y,int sudokuCheck[9][9])
{

    SDL_Texture *texture[9][9],*textureExit,*textureChange,*textureName,*textureHint,*textureDelete;
    SDL_Surface * surface = NULL;
    string a[9][9];
    changeIntergerToString(a[0],sudokuUpdate);


    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
        {
            if(sudokuCheck[i][j]!=0)
            {
                surface = TTF_RenderText_Solid(font,a[i][j].c_str(), {236,236,236});
                texture[i][j] = SDL_CreateTextureFromSurface(renderer,surface);
            }
            else if(sudokuCheck[i][j]==0&&sudokuZeRo[i][j]!=0)
            {
                surface = TTF_RenderText_Solid(font,a[i][j].c_str(), {223,0,41});
                texture[i][j] = SDL_CreateTextureFromSurface(renderer,surface);

            }
            else

            {
                surface = TTF_RenderText_Solid(font,a[i][j].c_str(), {91,189,43});
                texture[i][j] = SDL_CreateTextureFromSurface(renderer,surface);
            }

        }
    surface = TTF_RenderText_Solid(font,"H - HINT", {189,107,9});
    textureHint=SDL_CreateTextureFromSurface(renderer,surface);
    surface = TTF_RenderText_Solid(font,"B - BACK", {189,107,9});
    textureExit = SDL_CreateTextureFromSurface(renderer,surface);
    surface = TTF_RenderText_Solid(font,"C - CHANGE", {189,107,9});
    textureChange = SDL_CreateTextureFromSurface(renderer,surface);
    surface = TTF_RenderText_Solid(font,"SUDOKU", {189,107,9});
    textureName = SDL_CreateTextureFromSurface(renderer,surface);
    surface = TTF_RenderText_Solid(font,"D - DELETE", {189,107,9});
    textureDelete = SDL_CreateTextureFromSurface(renderer,surface);




    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture[0][0], NULL, NULL, &texW, &texH);

    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
        {
            if(*(sudokuUpdate+9*i+j)!=0)
            {
                SDL_Rect dstrect = { 110+j*40, 110+i*40, texW, texH };
                SDL_RenderCopy(renderer, texture[i][j], NULL, &dstrect);
            }

        }
    SDL_QueryTexture(textureExit, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 540, 100, texW, texH };
    SDL_RenderCopy(renderer, textureExit, NULL, &dstrect);
    SDL_QueryTexture(textureChange, NULL, NULL, &texW, &texH);
    dstrect = { 540, 180, texW, texH };
    SDL_RenderCopy(renderer, textureChange, NULL, &dstrect);
    SDL_QueryTexture(textureName, NULL, NULL, &texW, &texH);
    dstrect = { 230, 50, texW, texH };
    SDL_RenderCopy(renderer, textureName, NULL, &dstrect);
    SDL_QueryTexture(textureHint, NULL, NULL, &texW, &texH);
    dstrect = { 540, 260, texW, texH };
    SDL_RenderCopy(renderer, textureHint, NULL, &dstrect);
    SDL_QueryTexture(textureDelete, NULL, NULL, &texW, &texH);
    dstrect = { 540, 340, texW, texH };
    SDL_RenderCopy(renderer, textureDelete, NULL, &dstrect);
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            SDL_DestroyTexture(texture[i][j]);
    SDL_DestroyTexture(textureChange);
    SDL_DestroyTexture(textureExit);
    SDL_DestroyTexture(textureName);
    SDL_DestroyTexture(textureHint);
    SDL_DestroyTexture(textureDelete);
    SDL_FreeSurface(surface);

}
void addEvent(SDL_Renderer *renderer,TTF_Font * font,SDL_Event event,int &x,int &y,int *sudokuUpdate,int *sudokuCheck,int *sudokuResult,int *sudokuZeRo,bool  &quit)
{

    switch(event.key.keysym.sym)
    {
    case SDLK_UP:
        if(y>100)
            y=y-40;
        break;
    case SDLK_DOWN:
        if(y<420)
            y=y+40;
        break;
    case SDLK_LEFT:
        if(x>100)
            x=x-40;
        break;
    case SDLK_RIGHT:
        if(x<420)
            x=x+40;
        break;
    case SDLK_1:
        if(checkAddNumber(x,y,sudokuCheck))
            *(sudokuUpdate+(y-100)*9/40+(x-100)/40)=1;
        *(sudokuZeRo+(y-100)*9/40+(x-100)/40)=0;
        break;
    case SDLK_2:
        if(checkAddNumber(x,y,sudokuCheck))
            *(sudokuUpdate+(y-100)*9/40+(x-100)/40)=2;
        *(sudokuZeRo+(y-100)*9/40+(x-100)/40)=0;
        break;
    case SDLK_3:
        if(checkAddNumber(x,y,sudokuCheck))
            *(sudokuUpdate+(y-100)*9/40+(x-100)/40)=3;
        *(sudokuZeRo+(y-100)*9/40+(x-100)/40)=0;
        break;
    case SDLK_4:
        if(checkAddNumber(x,y,sudokuCheck))
            *(sudokuUpdate+(y-100)*9/40+(x-100)/40)=4;
        *(sudokuZeRo+(y-100)*9/40+(x-100)/40)=0;
        break;
    case SDLK_5:
        if(checkAddNumber(x,y,sudokuCheck))
            *(sudokuUpdate+(y-100)*9/40+(x-100)/40)=5;

        break;
    case SDLK_6:
        if(checkAddNumber(x,y,sudokuCheck))
            *(sudokuUpdate+(y-100)*9/40+(x-100)/40)=6;

        break;
    case SDLK_7:
        if(checkAddNumber(x,y,sudokuCheck))
            *(sudokuUpdate+(y-100)*9/40+(x-100)/40)=7;

        break;
    case SDLK_8:
        if(checkAddNumber(x,y,sudokuCheck))
            *(sudokuUpdate+(y-100)*9/40+(x-100)/40)=8;

        break;
    case SDLK_9:
        if(checkAddNumber(x,y,sudokuCheck))
            *(sudokuUpdate+(y-100)*9/40+(x-100)/40)=9;

        break;
    case SDLK_d:
        if(checkAddNumber(x,y,sudokuCheck))
            *(sudokuUpdate+(y-100)*9/40+(x-100)/40)=0;

        break;
    case SDLK_c:
        changeSudoku(sudokuUpdate,sudokuCheck,sudokuResult);
        break;
    case SDLK_b:
        writeFile("sudokuUpdate.txt",sudokuUpdate);
        writeFile("sudokuResult.txt",sudokuResult);
        writeFile("sudokuZero.txt",sudokuZeRo);
        writeFile("sudokuCheck.txt",sudokuCheck);
        quit=true;
        break;
    case SDLK_h:
        if(checkAddNumber(x,y,sudokuCheck))
        {
            *(sudokuUpdate+(y-100)*9/40+(x-100)/40)=*(sudokuResult+(y-100)*9/40+(x-100)/40);
            drawNotification(renderer,font);
        }
        break;

    }

    if(event.type==SDL_KEYUP)
        switch(event.key.keysym.sym)
        {
        case SDLK_UP:
            if(y>100)
                y=y+40;
            break;
        case SDLK_DOWN:
            if(y<420)
                y=y-40;
            break;
        case SDLK_LEFT:
            if(x>100)
                x=x+40;
            break;
        case SDLK_RIGHT:
            if (x<420)
                x=x-40;
            break;
        }

}
void drawYouWin(SDL_Renderer * renderer,TTF_Font * font)
{
    SDL_Texture *textureWin,*textureNext,*textureBack;
    SDL_Surface * surface = NULL;
    int texW=0;
    int texH=0;
    surface = TTF_RenderText_Solid(font,"COMPLETE!", {189,107,9});
    textureWin = SDL_CreateTextureFromSurface(renderer,surface);
    surface = TTF_RenderText_Solid(font,"N-NEXT", {189,107,9});
    textureNext = SDL_CreateTextureFromSurface(renderer,surface);
    surface = TTF_RenderText_Solid(font,"B-BACK TO MENU", {189,107,9});
    textureBack = SDL_CreateTextureFromSurface(renderer,surface);

    SDL_QueryTexture(textureWin, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 350,250, texW, texH };
    SDL_RenderCopy(renderer, textureWin,NULL, &dstrect);//
    SDL_QueryTexture(textureBack, NULL, NULL, &texW, &texH);
    dstrect = {100,500, texW, texH };
    SDL_RenderCopy(renderer, textureBack,NULL, &dstrect);//
    SDL_QueryTexture(textureNext, NULL, NULL, &texW, &texH);
    dstrect = { 700,500, texW, texH };
    SDL_RenderCopy(renderer, textureNext,NULL, &dstrect);
    SDL_DestroyTexture(textureBack);
    SDL_DestroyTexture(textureNext);
    SDL_DestroyTexture(textureWin);
    SDL_FreeSurface(surface);

}
void loadImage(SDL_Renderer * renderer)
{
    SDL_Surface *img = NULL;
    SDL_Texture *textureBackground;
    img = IMG_Load("background.png");
    textureBackground = SDL_CreateTextureFromSurface(renderer,img);
    SDL_RenderCopy(renderer, textureBackground,NULL, NULL);
    SDL_DestroyTexture(textureBackground);
    SDL_FreeSurface(img );

}
void runGame(SDL_Renderer * renderer,TTF_Font * font,bool &quit)
{
    int sudokuResult[9][9]= {0};
    int sudokuUpdate[9][9];
    int sudokuCheck[9][9];
    int sudokuZero[9][9]= {0};
    SDL_Event event;

    int x=100;
    int y=100;


    //loadData(&sudokuUpdate[0][0],"level_1.txt");
    changeSudoku(&sudokuUpdate[0][0],&sudokuCheck[0][0],&sudokuResult[0][0]);
    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }
        loadImage(renderer);
        if(!checkWin(sudokuUpdate[0],sudokuResult[0]))
        {

            addEvent(renderer,font,event,x,y,sudokuUpdate[0],sudokuCheck[0],sudokuResult[0],sudokuZero[0],quit);
            checkfull(&sudokuUpdate[0][0],&sudokuZero[0][0]);
            drawSudoku(renderer,x,y);
            drawData(renderer,font,&sudokuUpdate[0][0],sudokuZero,x,y,sudokuCheck);


        }
        else
        {
            drawYouWin(renderer,font);
            addEventYouWin( event,renderer,font,quit);
        }

        SDL_RenderPresent(renderer);
//  SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cout<<sudokuResult[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

}
void addEventYouWin(SDL_Event event,SDL_Renderer * renderer,TTF_Font * font,bool &quit)
{

    switch(event.key.keysym.sym)
    {
    case SDLK_n:
        runGame(renderer,font,quit);
        break;
    case SDLK_b :
        quit=true;
        break;

    }
}
void remuseGame(SDL_Renderer * renderer,TTF_Font * font,bool &quit)
{
    int sudokuResult[9][9]= {0};
    int sudokuUpdate[9][9];
    int sudokuCheck[9][9];
    int sudokuZero[9][9]= {0};
    SDL_Event event;

    int x=100;
    int y=100;


    loadData(&sudokuUpdate[0][0],"sudokuUpdate.txt");
    loadData(&sudokuCheck[0][0],"sudokuCheck.txt");
    loadData(&sudokuZero[0][0],"sudokuZero.txt");
    loadData(&sudokuResult[0][0],"sudokuResult.txt");

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }
        loadImage(renderer);
        if(!checkWin(sudokuUpdate[0],sudokuResult[0]))
        {

            addEvent(renderer,font,event,x,y,sudokuUpdate[0],sudokuCheck[0],sudokuResult[0],sudokuZero[0],quit);
            checkfull(&sudokuUpdate[0][0],&sudokuZero[0][0]);
             drawSudoku(renderer,x,y);
            drawData(renderer,font,&sudokuUpdate[0][0],sudokuZero,x,y,sudokuCheck);


        }
        else
        {
            drawYouWin(renderer,font);
            addEventYouWin( event,renderer,font,quit);
        }

        SDL_RenderPresent(renderer);
//  SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cout<<sudokuResult[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

}
void drawMenu(SDL_Renderer * renderer,TTF_Font * font)
{
    SDL_Texture *textureNewGame,*textureResumeGame,*textureExit,*textureSudoku;
    SDL_Surface * surface = NULL;
    int texW=0;
    int texH=0;
    surface = TTF_RenderText_Solid(font,"SUDOKU made by PT", {189,107,9});
    textureSudoku = SDL_CreateTextureFromSurface(renderer,surface);
    surface = TTF_RenderText_Solid(font,"N-NEW GAME", {189,107,9});
    textureNewGame = SDL_CreateTextureFromSurface(renderer,surface);
    surface = TTF_RenderText_Solid(font,"R-RESUME GAME", {189,107,9});
    textureResumeGame = SDL_CreateTextureFromSurface(renderer,surface);
    surface = TTF_RenderText_Solid(font,"E-EXIT", {189,107,9});
    textureExit = SDL_CreateTextureFromSurface(renderer,surface);

    SDL_QueryTexture(textureNewGame, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 300,200, texW, texH };
    SDL_RenderCopy(renderer, textureNewGame,NULL, &dstrect);//
    SDL_QueryTexture(textureResumeGame, NULL, NULL, &texW, &texH);
    dstrect = {300,250, texW, texH };
    SDL_RenderCopy(renderer, textureResumeGame,NULL, &dstrect);//
    SDL_QueryTexture(textureExit, NULL, NULL, &texW, &texH);
    dstrect = { 300,300, texW, texH };
    SDL_RenderCopy(renderer, textureExit,NULL, &dstrect);
    SDL_QueryTexture(textureSudoku, NULL, NULL, &texW, &texH);
    dstrect = { 250,100, texW, texH };
    SDL_RenderCopy(renderer, textureSudoku,NULL, &dstrect);
    SDL_DestroyTexture(textureExit);
    SDL_DestroyTexture(textureResumeGame);
    SDL_DestroyTexture(textureNewGame);
    SDL_FreeSurface(surface);

}
void addEventMenu(SDL_Event event,SDL_Renderer * renderer,TTF_Font * font,bool &quit,bool &quit2)
{
    switch(event.key.keysym.sym)
    {
    case SDLK_n:
        quit=false;
        runGame(renderer,font,quit);
        break;
    case SDLK_r:
        quit=false;
        remuseGame(renderer,font,quit);
        break;
    case SDLK_e:
        quit2 = true;
        quit=true;
        break;

    }
}

