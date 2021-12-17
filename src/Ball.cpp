#include "Ball.h"
#include <SDL.h>
#include <SDL_image.h> 
#include <System.h>





namespace cwing{ 
 
    Ball::Ball(int x, int y, int w, int h, Paddle* paddle):Component(x,y,w,h)
    {
		this->paddle = paddle;

    ball_tex = IMG_LoadTexture(sys.get_ren(), "/Users/kamal/Documents/images/ball.png");
    
    }



Ball* Ball::getInstance(int x, int y, int w, int h, Paddle* paddle)
{
    return new Ball(x, y, w, h, paddle);
}

Ball::~Ball()
{
SDL_DestroyTexture(ball_tex);
}



void Ball::draw() const
{
   SDL_RenderCopy(sys.get_ren(), ball_tex, NULL, &getRect());
}


void Ball::tick()
{
	if(gameStarted == true){ 
    	
		if (rect.x >= boundX || rect.x   <= 0)
		{
			changeHorizontalVelocity();
		}

		if (rect.y >= boundY || rect.y <= 0)
		{
			changeVerticalVelocity();
		}
		if (rect.y >= 600)
		{
			outOfBounds = true;
		}
		rect.y += verticalVelocity ;
		rect.x += horizontalVelocity;
	} else {
		rect.x = paddle->getRect().x;
		rect.y = paddle->getRect().y;
	}
	

}



void Ball::keyDown(const SDL_Event& eve)
{
 if (eve.key.keysym.sym == 32 && !gameStarted)
	startGame();
}


void Ball::mouseDown(const SDL_Event& eve)
{
	
SDL_Point p = {eve.button.x, eve.button.y};
	if(SDL_PointInRect(&p, &getRect())) {
		drag = true;
	}
 }


   void Ball::mouseUp(const SDL_Event& eve)
 {
	 SDL_Point g = {eve.button.x, eve.button.y};
	if(SDL_PointInRect(&g, &getRect())) {
		drag = false;
	}

 }
 

 void Ball::mouseMotion(const SDL_Event& eve)
 {
	 if(drag){ 
	 rect.x += eve.motion.xrel;
	 }
 }

 
/*
 void Ball::collision(Paddle& paddle, Ball& ball)
 {
	 if(!isIntersecting(paddle, ball)) return;

     ball.rect.y = -verticalVelocity;

if(ball.rect.x < paddle.rect.x)
ball.rect.x = -horizontalVelocity;
else 
ball.rect.x = horizontalVelocity;
 }
 */
}  