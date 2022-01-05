#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "Sprite.h"
#include <SDL.h>

namespace cwing
{

    class GameOver : public Sprite
    {
    public:
        static GameOver *getInstance(int x, int y, int w, int h, std::string bg);
        ~GameOver();
        void draw() const;
        void tick(){};
        bool isOutOfBounds() const;

    protected:
        GameOver(int x, int y, int w, int h, std::string bg);

    private:
        SDL_Texture *gameOver_tex;
    };
}

#endif