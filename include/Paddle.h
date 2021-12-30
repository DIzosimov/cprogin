#ifndef PADDLE_H
#define PADDLE_H
#include "Component.h"
#include <SDL.h>

namespace cwing
{

	class Paddle : public Component
	{
	public:
		static Paddle *getInstance(int x, int y, int w, int h);
		void mouseUp(const SDL_Event &);
		void mouseDown(const SDL_Event &);
		void mouseMotion(const SDL_Event &);
		void keyDown(const SDL_Event &eve);
		void draw() const;
		void tick() {}
		~Paddle();

	protected:
		Paddle(int x, int y, int w, int h);

	private:
		SDL_Texture *paddle_tex;
		bool drag = false;
	};

}
#endif

