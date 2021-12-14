#include "System.h"
#include <SDL.h>
//#include <SDL_image.h> 	
#include <string>

//std::string imagePath = "../../images/";

namespace cwing{

    System::System()
    {
        
        SDL_Init(SDL_INIT_EVERYTHING);
       // win = SDL_CreateWindow("Window", 100, 100, 800, 600, 0);
       // win = SDL_CreateWindow("Cwing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, 0);
        //ren = SDL_CreateRenderer(win, -1, 0);
        //bg_sur = IMG_Load( (imagePath + "background.jpg").c_str() );
        //bg_sur = IMG_LoadTexture(sys.get_ren(), "background.jpg");
        //bg_tex = SDL_CreateTextureFromSurface(sys.get_ren(), bg_sur);
	    //SDL_FreeSurface(bg_sur);
        
       
    }

    System::~System()
    {
        SDL_DestroyTexture(bg_sur);
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }


    SDL_Renderer* System::get_ren() const{
        return ren;
    }

    System sys;
}