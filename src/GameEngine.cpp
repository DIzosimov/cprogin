#include "GameEngine.h"
//#include <SDL.h> 	
#include "System.h"
#include "Component.h"
#include <SDL2/SDL.h>
#include <typeinfo>
#include "Bricks.h"
using namespace cwing;


using namespace std;

#define FPS 80

void GameEngine::add(Component* comp) {
	added.push_back(comp);
}

void GameEngine::remove(Component* comp) {
	removed.push_back(comp);
}


void GameEngine::run() {
	bool quit = false;

	Uint32 tickInterval = 1000 / FPS;
	while (!quit) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT: quit = true; break;
			case SDL_MOUSEBUTTONDOWN:
				for (Component* c : comps)
					c->mouseDown(event);
				break;
			case SDL_MOUSEBUTTONUP:
				for (Component* c : comps)
					c->mouseUp(event);   
				break;
			
			case SDL_MOUSEMOTION:
			  for(Component* c : comps)
					c->mouseMotion(event);   
				break;
			
			case SDL_KEYDOWN:
				for (Component* c : comps)
					c->keyDown(event); 
					break;
			
				
			}

		
			//switch
		} //inre while

		for (Component* c : comps)
			c->tick();


		for(Component* c : comps)
			if(c-> gameOver())
			  quit = true;
			  //c-> gameOver();

		for (Component* c : added)
			comps.push_back(c);
		added.clear();

		// for (Component* c : comps) {
		// 	if (c->collisionCheck()) {
		// 		for (Component*d : comps) {
		// 			if (typeid(d) == typeid(Bricks))
		// 				if (SDL_HasIntersection(c->getRect(), d->getRect()))
		// 					d->hit();
		// 		}
		// 	}
		// }

/*
		for (Component* c : comps)
			for (vector<Component*>::iterator i = comps.begin(); i != comps.end();)
				if (typeid(c) == typeid(Bricks)){
				//if (*i == c) {
					i = comps.erase(i);
				}
				else
					i++;
		//removed.clear();

*/
		
		for (Component* c : removed)
			for (vector<Component*>::iterator i = comps.begin();
				i != comps.end();)
				if (*i == c) {
					i = comps.erase(i);
				}
				else
					i++;
		removed.clear();

		SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
		SDL_RenderClear(sys.get_ren());
		for (Component* c : comps)
			c->draw();
		SDL_RenderPresent(sys.get_ren());

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	} // yttre while
}



