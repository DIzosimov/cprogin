#ifndef PADDLE_H
#define PADDLE_H
#include "Sprite.h"
#include <SDL.h>

namespace cwing
{

	class Paddle : public Sprite
	{
	public:
		static Paddle *getInstance(int x, int y, int w, int h, std::string bg);
		~Paddle();
		void mouseUp(const SDL_Event &);
		void mouseDown(const SDL_Event &);
		void mouseMotion(const SDL_Event &);
		void keyDown(const SDL_Event &eve);
		void draw() const;
		void tick() {}
		bool isOutOfBounds() const;

	protected:
		Paddle(int x, int y, int w, int h, std::string bg);

	private:
		SDL_Texture *paddle_tex;
		bool drag = false;
	};

}
#endif
