#include "GameEngine.h"
#include "GameWindow.h"
#include "Component.h"
#include <SDL2/SDL.h>
#include <typeinfo>
#include "Bricks.h"
#include <cmath>
#include "GameOver.h"

using namespace cwing;

using namespace std;

#define FPS 80

GameEngine::GameEngine(Paddle *paddle, Ball *ball, Background *background, GameOver *gameOver)
{
	this->paddle = paddle;
	this->ball = ball;
	this->background = background;
	this->gameOver = gameOver;
}

void GameEngine::add(Component *comp)
{
	added.push_back(comp);
}

void GameEngine::remove(Component *comp)
{
	removed.push_back(comp);
}

bool GameEngine::IntersectRect(const SDL_Rect &r1, const SDL_Rect &r2)
{
	double distX = abs(r1.x - r2.x - r2.w / 2);
	double distY = abs(r1.y - r2.y - r2.h / 2);
	double raduis = r1.w / (2 * 3.14);

	if (distX > (r2.w / 2 + raduis))
	{
		return false;
	}
	if (distY > (r2.h / 2 + raduis))
	{
		return false;
	}

	if (distX <= (r2.w / 2))
	{
		return true;
	}
	if (distY <= (r2.h / 2))
	{
		return true;
	}

	double dx = distX - r2.w / 2;
	double dy = distY - r2.h / 2;
	return (dx * dx + dy * dy <= (raduis * raduis));
}

void GameEngine::addBricks(Bricks *brick)
{
	added.push_back(brick);
	bricks.push_back(brick);
}

void GameEngine::run()
{
	bool quit = false;

	Uint32 tickInterval = 1000 / FPS;
	while (!quit)
	{
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				for (Component *c : comps)
					c->mouseDown(event);
				break;
			case SDL_MOUSEBUTTONUP:
				for (Component *c : comps)
					c->mouseUp(event);
				break;

			case SDL_MOUSEMOTION:
				for (Component *c : comps)
					c->mouseMotion(event);
				break;

			case SDL_KEYDOWN:
				for (Component *c : comps)
					c->keyDown(event);
				break;
			}

			//switch
		} //inre while

		for (Component *c : comps)
			c->tick();

		for (Component *c : comps)
			if (c->gameOver())
				quit = true;

		//	gameOver->getEndGame();
		//c-> gameOver();

		for (Component *c : added)
			comps.push_back(c);
		added.clear();

		if (ball->startGame())
		{

			int index = 0;
			for (Bricks *b : bricks)

				if (IntersectRect(ball->getRect(), b->getRect()))
				{
					ball->changeVerticalVelocity();
					b->hit();
					if (b->getIsBrickHit())
						bricks.erase(std::next(bricks.begin(), index));
					for (vector<Component *>::iterator i = comps.begin(); i != comps.end();)
						if (*i == b)
						{
							if (b->getIsBrickHit())
								i = comps.erase(i);
							else
								i++;
						}
						else
							i++;
				}
				else
					index++;

			if (IntersectRect(ball->getRect(), paddle->getRect()))
			{

				ball->changeVerticalVelocity();
			}
		}

		for (Component *c : removed)
			for (vector<Component *>::iterator i = comps.begin();
				 i != comps.end();)
				if (*i == c)
				{
					i = comps.erase(i);
				}
				else
					i++;
		removed.clear();

		SDL_SetRenderDrawColor(gw.get_ren(), 255, 255, 255, 255);
		SDL_RenderClear(gw.get_ren());
		for (Component *c : comps)
			c->draw();
		SDL_RenderPresent(gw.get_ren());

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	} // yttre while
}
