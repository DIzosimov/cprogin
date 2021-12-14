#include "Bricks.h"
#include <SDL.h>
#include <SDL_image.h> 
#include <System.h>




namespace cwing{ 
 
    Bricks::Bricks(int x, int y, int w, int h):Component(x,y,w,h)
    {

    bricks_tex = IMG_LoadTexture(sys.get_ren(), "/Users/kamal/Documents/images/block02.png");
    
    }



Bricks* Bricks::getInstance(int x, int y, int w, int h)
{
    return new Bricks(x, y, w, h);
}

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