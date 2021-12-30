#ifndef BRICKS_H
#define BRICKS_H
#include <SDL.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Component.h"

namespace cwing
{

	class Bricks : public Component
	{
	public:
		static Bricks *getInstance(int x, int y, int w, int h);
		void hit();
		void draw() const;
		void tick(){}
		~Bricks();
		bool getIsBrickHit() { return isBrickHit; }

	protected:
		Bricks(int x, int y, int w, int h);

	private:
		SDL_Texture *bricks_tex;

		bool isBrickHit = false;
		int currentHealth;
		int maxHealth;
	};
}
#endif