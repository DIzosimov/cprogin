#ifndef BALL_H
#define BALL_H
#include "Sprite.h"
#include "Paddle.h"
#include <SDL.h>

namespace cwing
{

    class Ball : public Sprite
    {
    public:
        static Ball *getInstance(int x, int y, int w, int h, std::string bg, Paddle *paddle);
        ~Ball();
        void draw() const;
        void tick();
        void changeHorizontalVelocity() { horizontalVelocity *= -1; }
        void changeVerticalVelocity() { verticalVelocity *= -1; }
        int getVerticalSize() const;
        int getHorizontalSize() const;
        void mouseDown(const SDL_Event &eve);
        void mouseUp(const SDL_Event &eve);
        void mouseMotion(const SDL_Event &eve);
        void keyDown(const SDL_Event &);
        bool startGame() { return gameStarted; }
        bool isOutOfBounds() const;

    protected:
        Ball(int x, int y, int w, int h, std::string bg, Paddle *paddle);

    private:
        SDL_Texture *ball_tex;
        int horizontalVelocity = -1;
        int verticalVelocity = -4;
        bool drag = false;
        bool gameStarted = false;
        int boundX = 800;
        int boundY = 600;
        Paddle *paddle;
    };

}

#endif