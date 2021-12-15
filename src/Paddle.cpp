#include "Paddle.h"
#include <SDL.h>
#include <SDL_image.h> 
#include <System.h>
#include <Component.h>

//std::string imagePath = "../../images/";

namespace cwing{ 
 //"c:/images/
    Paddle::Paddle(int x, int y, int w, int h):Component(x,y,w,h)
    {
	paddle_tex = IMG_LoadTexture(sys.get_ren(), "/Users/kamal/Documents/images/paddle.png");

    }






Paddle* Paddle::getInstance(int x, int y, int w, int h)
{
    return new Paddle(x, y, w, h);
}

Paddle::~Paddle()
{
SDL_DestroyTexture(paddle_tex);
}


void Paddle::tick(){
	if (rect.x > 0)
		rect.x -= paddleSpeed;
	else 
	   if(rect.x <= width - 90)
		rect.x += paddleSpeed;

}


void Paddle::mouseDown(const SDL_Event& eve)
{
SDL_Point p = {eve.button.x, eve.button.y};
	if(SDL_PointInRect(&p, &getRect()))
	drag = true;
 }

void Paddle::draw() const
{
   // if(drag)
   SDL_RenderCopy(sys.get_ren(), paddle_tex, NULL, &getRect());
}
    

void Paddle::setPaddlePositions(int w, int h)
{
	paddleX = (w / 2) - 40;
	paddleY = h - 40;
}

}