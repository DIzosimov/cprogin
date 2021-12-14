#include "Ball.h"
#include <SDL.h>
#include <SDL_image.h> 
#include <System.h>




namespace cwing{ 
 
    Ball::Ball(int x, int y, int w, int h):Component(x,y,w,h)
    {

    ball_tex = IMG_LoadTexture(sys.get_ren(), "/Users/kamal/Documents/images/ball.png");
    
    }



Ball* Ball::getInstance(int x, int y, int w, int h)
{
    return new Ball(x, y, w, h);
}

Ball::~Ball()
{
SDL_DestroyTexture(ball_tex);
}



void Ball::draw() const
{
   SDL_RenderCopy(sys.get_ren(), ball_tex, NULL, &getRect());
}
}  