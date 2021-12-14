#include "Background.h"
#include <SDL.h>
#include <SDL_image.h> 
#include <System.h>




namespace cwing{ 
 
    Background::Background(int x, int y, int w, int h):Component(x,y,w,h)
    {

    background_tex = IMG_LoadTexture(sys.get_ren(), "/Users/kamal/Documents/images/background.jpg");
    
    }



Background* Background::getInstance(int x, int y, int w, int h)
{
    return new Background(x, y, w, h);
}

Background::~Background()
{
SDL_DestroyTexture(background_tex);
}



void Background::draw() const
{
   SDL_RenderCopy(sys.get_ren(), background_tex, NULL, &getRect());
}
}  