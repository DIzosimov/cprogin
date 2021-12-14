#include "System.h"
#include <SDL.h>
#include <SDL_image.h> 	
#include <string>



namespace cwing{

    System::System()
    {
        
        SDL_Init(SDL_INIT_EVERYTHING);
        win = SDL_CreateWindow("Arkanoid Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
        ren = SDL_CreateRenderer(win, -1, 0);
        bg_sur  = IMG_LoadTexture(ren, "/Users/kamal/Documents/images/background.jpg");  
    }

    System::~System()
    {
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }


    SDL_Renderer* System::get_ren() const{
        return ren;
    }

    void System::draw() const
{
    	SDL_RenderClear(ren);
}

    System sys;
}