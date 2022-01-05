#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <SDL.h>
#include <SDL_ttf.h>

namespace cwing
{

    class GameWindow
    {
    public:
        GameWindow();
        ~GameWindow();
        SDL_Renderer *get_ren() const;

    private:
        SDL_Window *win;
        SDL_Renderer *ren;
        void draw() const;
    };

    extern GameWindow gw;
}

#endif