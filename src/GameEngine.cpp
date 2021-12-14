#include "GameEngine.h"
//#include <SDL.h> 	
#include "System.h"
#include "Component.h"
#include <SDL2/SDL.h>
using namespace cwing;


void GameEngine::add(Component* c)
{
	comps.push_back(c);
}

GameEngine::~GameEngine()
	{
	}
/*

	void GameEngine::run() {
	bool quit = false;
	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT: quit = true; break;
			case SDL_MOUSEBUTTONDOWN:
				for (Component* c : comps)
					c->mouseDown(event.button.x, event.button.y);
				break;
			case SDL_MOUSEBUTTONUP:
				for (Component* c : comps)
					c->mouseUp(event.button.x, event.button.y);
				break;
			} //switch
		} //inre while

		SDL_SetRenderDrawColor(sys.ren, 255, 255, 255, 255);
		SDL_RenderClear(sys.ren);
		for (Component* c : comps)
			c->draw();
		//SDL_RenderPresent(sys.ren);

	} // yttre while
}
GameEngine::~GameEngine()
	{
	}



	void GameEngine::run() {
		bool quit = false;
		bool drag = false;
		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_KEYDOWN:
				
				for (Component* c : comps)
						c->keyDown(eve);
					break;
				
				
				default:
					break;
				}
				
            
				} // switch
			} // inre while
              

			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			for (Component* c : comps)
				c->draw();
			SDL_RenderPresent(sys.get_ren());

		} //yttre while

//	}


	GameEngine::~GameEngine()
	{
	}

	
}
*/

/*
ase SDL_BUTTON_LEFT:
					for (Component* c : comps)
						c->keyUp(eve);
					break;
                case SDL_BUTTON_RIGHT:
					for (Component* c : comps)
						c->keyUp(eve);
					break;
                    */

				   /*
				   case SDL_MOUSEBUTTONDOWN:
					for (Component* c : comps)
						c->mouseDown(eve);
					break;
				case SDL_MOUSEBUTTONUP:
					for (Component* c : comps)
						c->mouseUp(eve);
					break;
				case SDL_KEYDOWN:
					for (Component* c : comps)
						c->keyDown(eve);
					break;
				case SDL_KEYUP:
					for (Component* c : comps)
						c->keyUp(eve);
					break;
					*/



/*
				case SDL_MOUSEBUTTONDOWN:{
					SDL_Point p = {eve.button.x, eve.button.y};
				//	if(SDL_PointInRect(&p))  //&paddle
					drag = true;
				}
					for (Component* c : comps)
						c->mouseDown(eve);
					break;
				case SDL_MOUSEMOTION:
					if(drag){
						//paddle.x += eve.motion.xrel;
						//paddle.y += eve.motion.yrel;
					}
					break;


					for (Component* c : comps)
				    c->tick();
					*/

				/*
				switch (eve.key.keysym.sym){
				case SDLK_RIGHT:  break;  //paddle.x++;
				case SDLK_LEFT: break; //paddle.x--;
				}
				*/