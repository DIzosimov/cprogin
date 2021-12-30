#include "Paddle.h"
#include <SDL.h>
#include <SDL_image.h>
#include "GameWindow.h"
#include <Component.h>
#include <iostream>
#include "Ball.h"

namespace cwing
{

	Paddle::Paddle(int x, int y, int w, int h) : Component(x, y, w, h)
	{
		paddle_tex = IMG_LoadTexture(gw.get_ren(), "/Users/kamal/Documents/images/paddle.png");
	}

	Paddle *Paddle::getInstance(int x, int y, int w, int h)
	{
		return new Paddle(x, y, w, h);
	}

	Paddle::~Paddle()
	{
		SDL_DestroyTexture(paddle_tex);
	}

	void Paddle::mouseDown(const SDL_Event &eve)
	{

		SDL_Point p = {eve.button.x, eve.button.y};
		if (SDL_PointInRect(&p, &getRect()))
		{
			drag = true;
		}
	}
	void Paddle::mouseUp(const SDL_Event &eve)
	{
		SDL_Point g = {eve.button.x, eve.button.y};
		if (SDL_PointInRect(&g, &getRect()))
		{
			drag = false;
		}
	}

	void Paddle::mouseMotion(const SDL_Event &eve)
	{
		if (drag)
		{
			rect.x += eve.motion.xrel;
		}
	}

	void Paddle::keyDown(const SDL_Event &eve)
	{
		switch (eve.key.keysym.sym)
		{
		case SDLK_RIGHT:
			if (rect.x < 691)
				rect.x += 25;
			break;
		case SDLK_LEFT:
			if (rect.x > 0)
				rect.x -= 25;
			break;
			drag = true;
		}
	}

	void Paddle::draw() const
	{

		SDL_RenderCopy(gw.get_ren(), paddle_tex, NULL, &getRect());
	}

}