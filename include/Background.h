#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Sprite.h"
#include <SDL.h>

namespace cwing
{

    class Background : public Sprite
    {
    public:
        static Background *getInstance(int x, int y, int w, int h, std::string bg);
        ~Background();
        void draw() const;
        void tick(){};
        bool isOutOfBounds() const;

    protected:
        Background(int x, int y, int w, int h, std::string bg);

    private:
        SDL_Texture *background_tex;
    };
}

#endif