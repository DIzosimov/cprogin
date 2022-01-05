#ifndef BRICK_H
#define BRICK_H
#include <SDL.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Sprite.h"

namespace cwing
{

	class Brick : public Sprite
	{
	public:
		static Brick *getInstance(int x, int y, int w, int h);
		void hit();
		void draw() const;
		void tick() {}
		~Brick();
		bool getIsBrickHit() { return isBrickHit; }
		bool isOutOfBounds() const;

	protected:
		Brick(int x, int y, int w, int h);

	private:
		SDL_Texture *bricks_tex;
		bool isBrickHit = false;
		int currentHealth;
		int maxHealth;
	};
}
#endif