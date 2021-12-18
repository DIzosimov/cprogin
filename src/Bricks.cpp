#include "Bricks.h"
#include <SDL.h>
#include <SDL_image.h> 
#include <System.h>
//#include <<SDL_image.h> 




namespace cwing{ 
 
    Bricks::Bricks(int x, int y, int w, int h):Component(x,y,w,h)
    {

	int randNum = rand()%(5-1 + 1) + 1;
            switch(randNum) {
                case 1: 
                    bricks_tex = IMG_LoadTexture(sys.get_ren(), "/Users/kamal/Documents/images/block01.png");
                    maxHealth = 1;
                    currentHealth = 1;
                    break;
                case 2:
                    bricks_tex = IMG_LoadTexture(sys.get_ren(), "/Users/kamal/Documents/images/block02.png");
                    maxHealth = 1;
                    currentHealth = 1;
                    break;
                case 3:
                    bricks_tex = IMG_LoadTexture(sys.get_ren(), "/Users/kamal/Documents/images/block03.png");
                    maxHealth = 2;
                    currentHealth = 2;
                    break;
                case 4:
                    bricks_tex = IMG_LoadTexture(sys.get_ren(), "/Users/kamal/Documents/images/block04.png");
                    maxHealth = 3;
                    currentHealth = 3;
                    break;
                default:
                    bricks_tex = IMG_LoadTexture(sys.get_ren(), "/Users/kamal/Documents/images/block01.png");
                    maxHealth = 1;
                    currentHealth = 1;
                    break;     
            }
    }



Bricks* Bricks::getInstance(int x, int y, int w, int h)
{
    return new Bricks(x, y, w, h);
}

void Bricks::hit()
{
    currentHealth--;
    if (currentHealth == 0) 
        isBrickHit = true;
}

/*
void Bricks::tick()
{
    if (isBrickHit)
        this->~Bricks();
}
*/

Bricks::~Bricks()
{
SDL_DestroyTexture(bricks_tex);
}



void Bricks::draw() const
{
   SDL_RenderCopy(sys.get_ren(), bricks_tex, NULL, &getRect());
}

/*
void Bricks:: InitializeBricks(int topSpacing)
{
	brickVector.clear();

	int horizontalSpacing = topSpacing;

	for (int i = 0; i < brickRows; i++)
	{
		int verticalSpacing = 10;
		for (int j = 0; j < brickColumns; j++)
		{
			brickVector.emplace_back(verticalSpacing, horizontalSpacing, brickRows - i);
			verticalSpacing += 88;
		}
		horizontalSpacing += 40;
	}
}
*/


/*
void Bricks:: hit()
{
	currentHealth--;
	if (currentHealth == 0)
	{
		isBrickHit = true;
	}
}
*/

}  