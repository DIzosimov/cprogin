#include "Paddle.h"
#include <SDL.h>
#include <SDL_image.h> 
#include <string>
#include <System.h>
//#include <Component.h>

std::string imagePath = "../../images/";

namespace cwing{ 

    Paddle::Paddle(int x, int y, int w, int h):Component(x,y,w,h)
    {
    //SDL_Surface* paddle_sur = IMG_Load( (imagePath + "paddle.png").c_str() );
	paddle_tex = IMG_LoadTexture(sys.get_ren(), "paddle.png");
    //paddle_tex  = SDL_CreateTextureFromSurface(sys.get_ren(), paddle_sur);
	//SDL_Rect paddleRect = {350, 550, paddle_sur->w, paddle_sur->h};
	//SDL_FreeSurface(paddle_sur);
    }






Paddle* Paddle::getInstance(int x, int y, int w, int h)
{
    return new Paddle(x, y, w, h);
}

Paddle::~Paddle()
{
SDL_DestroyTexture(paddle_tex);
}

void tick(){

}

void Paddle::mouseDown(const SDL_Event& eve)
{
SDL_Point p = {eve.button.x, eve.button.y};
	if(SDL_PointInRect(&p, &getRect()))
	drag = true;
 }

void Paddle::draw() const
{
    if(drag)
   SDL_RenderCopy(sys.get_ren(), paddle_tex, NULL, &getRect());
}
    

void Paddle::setPaddlePositions(int w, int h)
{
	paddleX = (w / 2) - 40;
	paddleY = h - 40;
}

void Paddle::moveLeft()
{
	if (getPaddleX() > 0)
		paddleX -= paddleSpeed;
}

void Paddle::moveRight()
{
	if (getPaddleX() <= width - 90)
		paddleX += paddleSpeed;
}
}