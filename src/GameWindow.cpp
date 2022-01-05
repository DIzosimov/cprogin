#include "GameWindow.h"
#include <SDL.h>
#include <SDL_image.h>

namespace cwing
{

    GameWindow::GameWindow()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        win = SDL_CreateWindow("Arkanoid Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
        ren = SDL_CreateRenderer(win, -1, 0);
    }

    GameWindow::~GameWindow()
    {
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }

    SDL_Renderer *GameWindow::get_ren() const
    {
        return ren;
    }

    void GameWindow::draw() const
    {
        SDL_RenderClear(ren);
    }

    GameWindow gw;
}