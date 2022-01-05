#ifndef GameEngine_H
#define GameEngine_H
#include <vector>
#include "Sprite.h"
#include <Ball.h>
#include <Paddle.h>
#include <Brick.h>

namespace cwing
{

	class GameEngine
	{
	public:
		GameEngine(Ball *ball, Paddle *paddle);
		void add(Sprite *comp);
		void remove(Sprite *comp);
		void run();
		void addBricks(Brick *brick);
		bool IntersectRect(const SDL_Rect &r1, const SDL_Rect &r2);

	private:
		std::vector<Sprite *> comps;
		std::vector<Sprite *> added, removed;
		std::vector<Brick *> bricks;
		Ball *ball;
		Paddle *paddle;
	};

}
#endif
