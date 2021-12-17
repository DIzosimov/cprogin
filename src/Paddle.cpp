#include "Paddle.h"
#include <SDL.h>
#include <SDL_image.h> 
#include <System.h>
#include <Component.h>
#include <iostream>
#include "Ball.h"



namespace cwing{ 

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
	if (drag) {
		moveLeft();
	} else 
	   moveRight();

}


void Paddle::mouseDown(const SDL_Event& eve)
{
	
SDL_Point p = {eve.button.x, eve.button.y};
	if(SDL_PointInRect(&p, &getRect())) {
		drag = true;
	}
 }
  void Paddle::mouseUp(const SDL_Event& eve)
 {
	 SDL_Point g = {eve.button.x, eve.button.y};
	if(SDL_PointInRect(&g, &getRect())) {
		drag = false;
	}

 }

 void Paddle::mouseMotion(const SDL_Event& eve)
 {
	 if(drag){ 
	 rect.x += eve.motion.xrel;
	 }
 }

void Paddle::draw() const
{

   SDL_RenderCopy(sys.get_ren(), paddle_tex, NULL, &getRect());
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