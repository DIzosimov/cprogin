#ifndef BRICKS_H
#define BRICKS_H

#include <SDL.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Component.h"

namespace cwing{ 

class Bricks : public Component 
{
public:
    static Bricks* getInstance(int x, int y, int w, int h);
	//void InitializeBricks(int topSpacing);
	//std::vector<Brick>* getBricks() { return &brickVector; };
	static const int brickRows = 5;
	static const int brickColumns = 9;
    //bool isHit() { return isBrickHit; };
    void hit();
    void draw() const;
    void tick() {};
    //Brick();
	//Brick( int verticalSpacing, int horizontalSpacing, int life );
    ~Bricks();
protected:
		Bricks(int x, int y, int w, int h);

private:
	std::vector<Bricks> brickVector;
    SDL_Texture* bricks_tex ;
	
    //bool isBrickHit = false;
	//int brickWidth = 80;
	//int brickHeight = 34;
	//int currentHealth;
	//int maxHealth;
};
}
#endif