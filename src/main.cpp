#include <iostream>
#include <string>
#include <Paddle.h>
#include <GameEngine.h>
#include "Background.h"
#include "Ball.h"
#include "Bricks.h"



// Alla dessa SDL inkluderingsfiler används inte i detta testprogram.
// Bifogas endast för test av SDL installation! 

#include <SDL.h> 			//<SDL2/SDL.h>
#include <SDL_image.h> 		//<SDL2_image/SDL_image.h>
#include <SDL_mixer.h> 		//<SDL2_mixer/SDL_mixer.h>
#include <SDL_ttf.h> 		//<SDL2_ttf/SDL_ttf.h>

//#define FPS 60
using namespace cwing;

int main(int argc, char* argv[]) {


	cwing::GameEngine ses;
	Background* b = Background::getInstance(0, 0, 800, 600);
	ses.add(b);
	Paddle* p = Paddle::getInstance(330, 590, 100, 10);
	ses.add(p);
	Ball* g = Ball::getInstance(0, 0, 13, 13, p);
	ses.add(g);
	

	for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= 10; j++) {
            Bricks* t = Bricks::getInstance(i*40, j*20, 48, 20);
				ses.add(t);
        }
	
    }
	ses.run();

	


     return 0;
}