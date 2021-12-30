#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>

namespace cwing
{
	class Component
	{

	public:
		virtual ~Component();
		virtual void mouseDown(const SDL_Event &) {}
		virtual void mouseMotion(const SDL_Event &) {}
		virtual void mouseUp(const SDL_Event &) {}
		virtual void keyDown(const SDL_Event &) {}
		virtual void keyUp(const SDL_Event &) {}
		virtual void draw() const = 0;
		virtual void tick() = 0;
		virtual bool startGame() { return gameStarted; }
		virtual bool gameOver() { return false; }
		virtual bool getEndGame() { return endGame = true; }
		const SDL_Rect &getRect() const { return rect; }
		virtual void hit() {}

	protected:
		Component(int x, int y, int w, int h);
		SDL_Rect rect;

	private:
		Component(const Component &) = delete;
		const Component &operator=(const Component &) = delete;
		bool gameStarted = false;
		bool endGame = false;
	};
}
#endif