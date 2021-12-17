#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>

namespace cwing {
	class Component
	{
       
	public:
		virtual ~Component();
		virtual void mouseDown(const SDL_Event&) {}
		virtual void mouseMotion (const SDL_Event&) {}   
		virtual void mouseUp(const SDL_Event&) {}
        virtual void mouseRight(const SDL_Event&) {}
        virtual void mouseLeft(const SDL_Event&) {}
		virtual void keyDown(const SDL_Event&) {}
		virtual void keyUp(const SDL_Event&) {}
        virtual void keyRight(const SDL_Event&) {}
        virtual void keyLeft(const SDL_Event&) {}
		virtual void draw() const = 0;
	    virtual void tick() = 0;
		virtual bool gameOver(){return false;}
		const SDL_Rect& getRect() const { return rect; }

	protected:
		Component(int x, int y, int w, int h);
		SDL_Rect rect;
	private:
		
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;
	};
}
#endif