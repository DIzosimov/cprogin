#include "Ball.h"
#include <SDL.h>
#include <SDL_image.h>
#include "GameWindow.h"

namespace cwing

{

	Ball::Ball(int x, int y, int w, int h, std::string bg, Paddle *paddle) : Sprite(x, y, w, h)
	{
		this->paddle = paddle;

		ball_tex = IMG_LoadTexture(gw.get_ren(), (Sprite::resPath + bg).c_str());
	}

	Ball *Ball::getInstance(int x, int y, int w, int h, std::string bg, Paddle *paddle)
	{
		return new Ball(x, y, w, h, bg, paddle);
	}

	Ball::~Ball()
	{
		SDL_DestroyTexture(ball_tex);
	}

	bool Ball::isOutOfBounds() const
	{
		return Sprite::outOfBounds;
	}

	void Ball::draw() const
	{
		if (!isOutOfBounds())
			SDL_RenderCopy(gw.get_ren(), ball_tex, NULL, &getRect());
	}

	void Ball::tick()
	{
		rect.y += verticalVelocity;
		rect.x += horizontalVelocity;

		if (startGame())
		{

			if (rect.x >= boundX || rect.x <= 0)
			{
				changeHorizontalVelocity();
			}

			if (rect.y >= boundY || rect.y <= 0)
			{
				changeVerticalVelocity();
			}
			if (rect.y >= 600)
			{
				Sprite::outOfBounds = true;
			}
		}
		else
		{
			rect.x = paddle->getRect().x + 45;
			rect.y = paddle->getRect().y - 12;
		}
	}

	void Ball::keyDown(const SDL_Event &eve)
	{
		if (eve.key.keysym.sym == 32 && !gameStarted)
			gameStarted = true;
	}

	void Ball::mouseDown(const SDL_Event &eve)
	{

		SDL_Point p = {eve.button.x, eve.button.y};
		if (SDL_PointInRect(&p, &getRect()))
		{
			drag = true;
		}
	}

	void Ball::mouseUp(const SDL_Event &eve)
	{
		SDL_Point g = {eve.button.x, eve.button.y};
		if (SDL_PointInRect(&g, &getRect()))
		{
			drag = false;
		}
	}

	void Ball::mouseMotion(const SDL_Event &eve)
	{
		if (drag)
		{
			rect.x += eve.motion.xrel;
		}
	}

}