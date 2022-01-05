#include "Paddle.h"
#include <SDL.h>
#include <SDL_image.h>
#include "GameWindow.h"
#include <iostream>

namespace cwing
{

	Paddle::Paddle(int x, int y, int w, int h, std::string bg) : Sprite(x, y, w, h)
	{
		paddle_tex = IMG_LoadTexture(gw.get_ren(), (Sprite::resPath + bg).c_str());
	}

	Paddle *Paddle::getInstance(int x, int y, int w, int h, std::string bg)
	{
		return new Paddle(x, y, w, h, bg);
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

	bool Paddle::isOutOfBounds() const
	{
		return Sprite::outOfBounds;
	}

	void Paddle::draw() const
	{
		if (!isOutOfBounds())
			SDL_RenderCopy(gw.get_ren(), paddle_tex, NULL, &getRect());
	}
}