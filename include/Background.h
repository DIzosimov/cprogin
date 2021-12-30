#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Component.h"

#include <SDL.h>

namespace cwing
{

    class Background : public Component
    {
    public:
        static Background *getInstance(int x, int y, int w, int h);
        void draw() const;
        void tick(){};
        ~Background();

    protected:
        Background(int x, int y, int w, int h);

    private:
        SDL_Texture *background_tex;
    };
}

#endif