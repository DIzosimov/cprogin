#include "GameOver.h"
#include <SDL.h>
#include <SDL_image.h> 
#include "GameWindow.h"






namespace cwing{ 
 
    GameOver::GameOver(int x, int y, int w, int h):Component(x,y,w,h)
    {
	

    gameOver_tex = IMG_LoadTexture(gw.get_ren(), "/Users/kamal/Documents/images/GameOver.png");
    
    }



GameOver* GameOver::getInstance(int x, int y, int w, int h)
{
    return new GameOver(x, y, w, h);
}

GameOver::~GameOver()
{
SDL_DestroyTexture(gameOver_tex);
}



void GameOver::draw() const
{

     
        SDL_RenderCopy(gw.get_ren(), gameOver_tex, NULL, &getRect());
}


void GameOver::tick() 
{
if(getEndGame()){
    draw();
}
}

}