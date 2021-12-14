#include <iostream>
#include <string>
#include <Paddle.h>
#include <GameEngine.h>

// Alla dessa SDL inkluderingsfiler används inte i detta testprogram.
// Bifogas endast för test av SDL installation! 

#include <SDL.h> 			//<SDL2/SDL.h>
#include <SDL_image.h> 		//<SDL2_image/SDL_image.h>
#include <SDL_mixer.h> 		//<SDL2_mixer/SDL_mixer.h>
#include <SDL_ttf.h> 		//<SDL2_ttf/SDL_ttf.h>

//#define FPS 60

using namespace cwing;


int main(int argc, char* argv[]) {

	//SDL_Delay(10000);

	// Paths to resources
	
	std::string imagePath = "../../images/";
	std::string fontPath = "../../fonts/";
	std::string soundPath = "../../sounds/";

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
	{
		std::cout << "Error SDL2 Initialization : " << SDL_GetError();
		return EXIT_FAILURE;
	}

	if (TTF_Init() < 0)
	{
		std::cout << "Error SDL_ttf Initialization : " << SDL_GetError();
		return EXIT_FAILURE;
	}
	
	SDL_Window* window 		= SDL_CreateWindow("Window", 100, 100, 800, 600, 0);
	SDL_Renderer* renderer 	= SDL_CreateRenderer(window, -1, 0);


	SDL_Surface* bg_sur = IMG_Load( (imagePath + "background.jpg").c_str() );

 

    SDL_Surface* block01_sur = IMG_Load( (imagePath + "block01.png").c_str() );

    SDL_Surface* ball_sur = IMG_Load( (imagePath + "ball.png").c_str() );

	SDL_Texture* bg_tex = SDL_CreateTextureFromSurface(renderer, bg_sur);
	SDL_FreeSurface(bg_sur);

   

	


	SDL_Texture* ball_tex  = SDL_CreateTextureFromSurface(renderer, ball_sur);
	SDL_Rect ballRect = {390, 540, ball_sur->w, ball_sur->h};
	SDL_FreeSurface(ball_sur);

	SDL_Texture* block01_tex  = SDL_CreateTextureFromSurface(renderer, block01_sur);
	SDL_Rect block01Rect = {100, 100, block01_sur->w, block01_sur->h};
	SDL_FreeSurface(block01_sur);

//Paddle* p = Paddle::getInstance(350, 350, 80, 20);

    GameEngine ses;
	Paddle* p = Paddle::getInstance(350, 350, 80, 20);
	ses.add(p);
	



	std::cout << "Avsluta programmet genom \"quit\" från fönstrets meny eller genom att stänga fönstret!" << std::endl;

	// Loop till dess att programmet avslutas!
	bool running = true;
	while (running) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				running = false;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bg_tex, NULL, NULL);
		//SDL_RenderCopy(renderer, p.draw, NULL, &p);
		SDL_RenderCopy(renderer, ball_tex, NULL, &ballRect);
		SDL_RenderCopy(renderer, block01_tex, NULL, &block01Rect);
		SDL_RenderPresent(renderer);
	}

	// Städa innan programmet avslutas!

	SDL_DestroyTexture(bg_tex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	TTF_Quit();
	SDL_Quit();
	
	return EXIT_SUCCESS;
	

     return 0;
}