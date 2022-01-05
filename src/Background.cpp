#include "Background.h"
#include <SDL.h>
#include <SDL_image.h>
#include "GameWindow.h"

namespace cwing
{

    Background::Background(int x, int y, int w, int h, std::string bg) : Sprite(x, y, w, h)
    {
        background_tex = IMG_LoadTexture(gw.get_ren(), (Sprite::resPath + bg).c_str());
    }

    Background *Background::getInstance(int x, int y, int w, int h, std::string bg)
    {
        return new Background(x, y, w, h, bg);
    }

    Background::~Background()
    {
        SDL_DestroyTexture(background_tex);
    }

    bool Background::isOutOfBounds() const
    {
        return Sprite::outOfBounds;
    }

    void Background::draw() const
    {
        if (!isOutOfBounds())
            SDL_RenderCopy(gw.get_ren(), background_tex, NULL, &getRect());
    }
}