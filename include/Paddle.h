#ifndef PADDLE_H
#define PADDLE_H
#include "Component.h"

#include <SDL.h>



namespace cwing{ 

class Paddle : public Component 
{
public:

    static Paddle* getInstance(int x, int y, int w, int h);
	//void setParams(int w) { width = w; };
	//SDL_Rect paddleRect() { return { paddleX, paddleY, 80, 20 }; };
	void setPaddlePositions(int w, int h);
	int getPaddleX() { return paddleX; }
	int getPaddleY() { return paddleY; }
    void mouseDown(const SDL_Event&) ;
    void mouseMotion(const SDL_Event&);
	void moveLeft();
	void moveRight();
    void draw() const;
    void tick();
    ~Paddle();
	void mouseUp(const SDL_Event&);
protected:
		Paddle(int x, int y, int w, int h);
	

private:
	int width;
	int paddleX = 0, paddleY = 0;
	int paddleSpeed = 2;
    SDL_Texture* paddle_tex;
    bool drag = false;
};
}
#endif




/*
void setParams(int w) { width = w; };
SDL_Rect paddleRect() { return { paddleX, paddleY, 80, 20 }; };
*/