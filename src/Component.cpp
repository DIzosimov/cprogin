#include "Component.h"
#include "Paddle.h"
#include "Ball.h"
#include "Bricks.h"

namespace cwing {

	Component::Component(int x, int y, int w, int h) :rect{ x,y,w,h }
	{
	}

	Component::~Component()
	{
	}
}