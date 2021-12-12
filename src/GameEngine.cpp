#include "GameEngine.h"
#include <SDL.h> 	
#include "System.h"

namespace cwing {

	void GameEngine::add(Component* c) {
		comps.push_back(c);
	}

	void GameEngine::run() {
		bool quit = false;
		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT: quit = true; break;
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
            
				} // switch
			} // inre while
			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			for (Component* c : comps)
				c->draw();
			SDL_RenderPresent(sys.get_ren());

		} //yttre while

	}

	GameEngine::~GameEngine()
	{
	}
}


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