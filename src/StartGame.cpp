#include "StartGame.h"
#include <SDL.h>
#include <SDL_image.h> 
#include <System.h>






namespace cwing{ 
 
    StartGame::StartGame(int x, int y, int w, int h):Component(x,y,w,h)
    {
	

    startGame_tex = IMG_LoadTexture(sys.get_ren(), "/Users/kamal/Documents/images/NewGame.png");
    
    }



StartGame* StartGame::getInstance(int x, int y, int w, int h)
{
    return new StartGame(x, y, w, h);
}

StartGame::~StartGame()
{
SDL_DestroyTexture(startGame_tex);
}



void StartGame::draw() const
{

     //if(isDown)
   SDL_RenderCopy(sys.get_ren(), startGame_tex, NULL, &getRect());
}

void StartGame::mouseDown(const SDL_Event& eve)
{
SDL_Point p = {eve.button.x, eve.button.y};
	if(SDL_PointInRect(&p, &getRect())) {
		isDown = true;
       
	}


 }




   void StartGame::mouseUp(const SDL_Event& eve)
 {
	isDown = false;

 }


 //bool StartGame::quitGame()

}