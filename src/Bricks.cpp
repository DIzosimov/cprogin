#include "Bricks.h"
#include <SDL.h>
#include <SDL_image.h>
#include <GameWindow.h>
#include "Bricks.h"

namespace cwing
{

    Bricks::Bricks(int x, int y, int w, int h) : Component(x, y, w, h)
    {

        int randNum = rand() % (4 - 1 + 1) + 1;
        switch (randNum)
        {
        case 1:
            bricks_tex = IMG_LoadTexture(gw.get_ren(), "/Users/kamal/Documents/images/block01.png");
            maxHealth = 1;
            currentHealth = 1;
            break;
        case 2:
            bricks_tex = IMG_LoadTexture(gw.get_ren(), "/Users/kamal/Documents/images/block02.png");
            maxHealth = 1;
            currentHealth = 1;
            break;
        case 3:
            bricks_tex = IMG_LoadTexture(gw.get_ren(), "/Users/kamal/Documents/images/block03.png");
            maxHealth = 2;
            currentHealth = 2;
            break;
        case 4:
            bricks_tex = IMG_LoadTexture(gw.get_ren(), "/Users/kamal/Documents/images/block04.png");
            maxHealth = 3;
            currentHealth = 3;
            break;
        default:
            bricks_tex = IMG_LoadTexture(gw.get_ren(), "/Users/kamal/Documents/images/block01.png");
            maxHealth = 1;
            currentHealth = 1;
            break;
        }
    }

    Bricks *Bricks::getInstance(int x, int y, int w, int h)
    {
        return new Bricks(x, y, w, h);
    }

    void Bricks::hit()
    {
        currentHealth--;
        if (currentHealth == 0)
            isBrickHit = true;
    }

    Bricks::~Bricks()
    {
        SDL_DestroyTexture(bricks_tex);
    }

    void Bricks::draw() const
    {
        SDL_RenderCopy(gw.get_ren(), bricks_tex, NULL, &getRect());
    }

}