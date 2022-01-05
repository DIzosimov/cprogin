#include <iostream>
#include <string>

#include "Background.h"
#include "Ball.h"
#include "Brick.h"
#include "GameEngine.h"
#include "GameOver.h"
#include "Paddle.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

using namespace cwing;

int main(int argc, char *argv[])
{
	Background *background = Background::getInstance(0, 0, 800, 600, "background.jpg");
	Paddle *paddle = Paddle::getInstance(330, 590, 100, 10, "paddle.png");
	Ball *ball = Ball::getInstance(0, 0, 13, 13, "ball.png", paddle);
	GameOver *gameOver = GameOver::getInstance(0, 0, 800, 600, "GameOver.png");

	cwing::GameEngine ses(ball, paddle);

	ses.add(background);
	ses.add(paddle);
	ses.add(ball);
	ses.add(gameOver);

	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			Brick *bricks = Brick::getInstance(i * 40, j * 20, 40, 20);
			ses.addBricks(bricks);
		}
	}

	ses.run();

	return 0;
}