#ifndef BALL_H
#define BALL_H
#include "Component.h"
#include "Paddle.h"
#include "Bricks.h"
#include <SDL.h>


namespace cwing{ 

class Ball : public Component 
{
public:

    static Ball* getInstance(int x, int y, int w, int h, Paddle* paddle);
    void draw() const;
    void tick();
    ~Ball();
    void changeHorizontalVelocity() { horizontalVelocity *= -1; }
    void changeVerticalVelocity() { verticalVelocity *= -1; }
    bool isOutOfBounds() const { return outOfBounds; }
    int getVerticalSize() const;
    int getHorizontalSize() const;
    void mouseDown(const SDL_Event& eve);
    void mouseMotion(const SDL_Event& eve);
    void keyDown(const SDL_Event&);
    void mouseUp(const SDL_Event& eve);
    void startGame() { gameStarted = true; }
    bool gameOver(){ return outOfBounds;}  
    bool IntersectRect(const SDL_Rect & r1, const SDL_Rect & r2);
protected:
		Ball(int x, int y, int w, int h, Paddle* paddle);

private:
    SDL_Texture* ball_tex;
    bool outOfBounds = false;
    int horizontalVelocity = -2; //randomize direction
    int verticalVelocity = -4;
	int ballX = 0, ballY = 0;
    bool drag = false;
    bool gameStarted = false;
    int boundX = 800;
    int boundY = 600;
    Paddle* paddle;
    Ball* ball;
   
  

  
    
};
}

#endif