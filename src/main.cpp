#include <iostream>
#include <string>
#include <Paddle.h>
#include <GameEngine.h>
#include "Background.h"
#include "Ball.h"
#include "Bricks.h"
#include "StartGame.h"
#include "GameOver.h"


// Alla dessa SDL inkluderingsfiler används inte i detta testprogram.
// Bifogas endast för test av SDL installation! 

#include <SDL.h> 			//<SDL2/SDL.h>
#include <SDL_image.h> 		//<SDL2_image/SDL_image.h>
#include <SDL_mixer.h> 		//<SDL2_mixer/SDL_mixer.h>
#include <SDL_ttf.h> 		//<SDL2_ttf/SDL_ttf.h>

//#define FPS 60
using namespace cwing;

int main(int argc, char* argv[]) {

	Background* background = Background::getInstance(0, 0, 800, 600);
    Paddle* p = Paddle::getInstance(330, 590, 100, 10);
	
	Ball* ball = Ball::getInstance(0, 0, 13, 13, p);

		GameOver* o = GameOver::getInstance(0, 0, 800, 600);


	cwing::GameEngine ses(p, ball, background, o);

	
//StartGame* s = StartGame::getInstance(0, 0, 800, 600);
//	ses.add(s);

        
	
	//if(s->startGame()){ 
    // std::cout<<"Hej"<<std::endl;
	Background* b = Background::getInstance(0, 0, 800, 600);
	ses.add(b);
	
	ses.add(p);
	
	ses.add(ball);
	

	for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= 10; j++) {
            Bricks* t = Bricks::getInstance(i*40, j*20, 40, 20);
				ses.add(t);
				ses.addBricks(t);
        }
	
    }
	
		//}
		
		if(o->getEndGame()){
		
			ses.add(o);
		}
		
		


/*
	    if (s->quitGame()){

		}
		*/

          ses.run();      

     return 0;
		}