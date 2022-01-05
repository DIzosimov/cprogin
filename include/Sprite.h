#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <string>

namespace cwing
{
	class Sprite
	{

	public:
		virtual ~Sprite();
		virtual void mouseDown(const SDL_Event &) {}
		virtual void mouseMotion(const SDL_Event &) {}
		virtual void mouseUp(const SDL_Event &) {}
		virtual void keyDown(const SDL_Event &) {}
		virtual void keyUp(const SDL_Event &) {}
		virtual void draw() const = 0;
		virtual void tick() = 0;
		virtual bool startGame() { return gameStarted; }
		virtual bool gameOver() { return false; }
		const SDL_Rect &getRect() const { return rect; }
		bool isOutOfBounds() const { return outOfBounds; }

	protected:
		Sprite(int x, int y, int w, int h);
		SDL_Rect rect;
		static bool outOfBounds;
		std::string resPath = "../../images/";

	private:
		Sprite(const Sprite &) = delete;
		const Sprite &operator=(const Sprite &) = delete;
		bool gameStarted = false;
	};
}
#endif