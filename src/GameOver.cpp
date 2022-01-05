#include "GameOver.h"
#include <SDL.h>
#include <SDL_image.h>
#include "GameWindow.h"

namespace cwing
{

    GameOver::GameOver(int x, int y, int w, int h, std::string bg) : Sprite(x, y, w, h)
    {

        gameOver_tex = IMG_LoadTexture(gw.get_ren(), (Sprite::resPath + bg).c_str());
    }

    GameOver *GameOver::getInstance(int x, int y, int w, int h, std::string bg)
    {
        return new GameOver(x, y, w, h, bg);
    }

    GameOver::~GameOver()
    {
        SDL_DestroyTexture(gameOver_tex);
    }

    bool GameOver::isOutOfBounds() const
    {
        return Sprite::outOfBounds;
    }

    void GameOver::draw() const
    {

        if (isOutOfBounds())
            SDL_RenderCopy(gw.get_ren(), gameOver_tex, NULL, &getRect());
    }
}