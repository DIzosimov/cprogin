#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>


namespace cwing {

    class System
    {
        public:
        System();
        ~System();
        SDL_Renderer* get_ren() const;
        private:
        SDL_Window* win;
        SDL_Renderer* ren;
    };

    extern System sys;
}

#endif