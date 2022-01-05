#include "Brick.h"
#include <SDL.h>
#include <SDL_image.h>
#include <GameWindow.h>

namespace cwing
{
    Brick::Brick(int x, int y, int w, int h) : Sprite(x, y, w, h)
    {
        int randNum = rand() % (4 - 1 + 1) + 1;
        switch (randNum)
        {
        case 1:
            bricks_tex = IMG_LoadTexture(gw.get_ren(), (Sprite::resPath + "block01.png").c_str());
            maxHealth = 1;
            currentHealth = 1;
            break;
        case 2:
            bricks_tex = IMG_LoadTexture(gw.get_ren(), (Sprite::resPath + "block02.png").c_str());
            maxHealth = 1;
            currentHealth = 1;
            break;
        case 3:
            bricks_tex = IMG_LoadTexture(gw.get_ren(), (Sprite::resPath + "block03.png").c_str());
            maxHealth = 2;
            currentHealth = 2;
            break;
        case 4:
            bricks_tex = IMG_LoadTexture(gw.get_ren(), (Sprite::resPath + "block04.png").c_str());
            maxHealth = 3;
            currentHealth = 3;
            break;
        default:
            bricks_tex = IMG_LoadTexture(gw.get_ren(), (Sprite::resPath + "block01.png").c_str());
            maxHealth = 1;
            currentHealth = 1;
            break;
        }
    }

    Brick *Brick::getInstance(int x, int y, int w, int h)
    {
        return new Brick(x, y, w, h);
    }

    void Brick::hit()
    {
        currentHealth--;
        if (currentHealth == 0)
            isBrickHit = true;
    }

    Brick::~Brick()
    {
        SDL_DestroyTexture(bricks_tex);
    }

    bool Brick::isOutOfBounds() const
    {
        return Sprite::outOfBounds;
    }

    void Brick::draw() const
    {
        if (!isOutOfBounds())
            SDL_RenderCopy(gw.get_ren(), bricks_tex, NULL, &getRect());
    }
}