#ifndef GameEngine_H
#define GameEngine_H

#include <vector>
#include "Component.h"
#include <Ball.h>
#include <Paddle.h>
#include <Bricks.h>
#include "Background.h"
#include "GameOver.h"

namespace cwing
{

	class GameEngine
	{
	public:
		GameEngine(Paddle *paddle, Ball *ball, Background *background, GameOver *gameOver);
		void add(Component *comp);
		void remove(Component *comp);
		void run();
		void addBricks(Bricks *brick);
		bool IntersectRect(const SDL_Rect &r1, const SDL_Rect &r2);

	private:
		std::vector<Component *> comps;
		std::vector<Component *> added, removed;
		std::vector<Bricks *> bricks;

		Ball *ball;
		Paddle *paddle;
		Background *background;
		GameOver *gameOver;
	};

}
#endif
