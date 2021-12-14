#ifndef BALL_H
#define BALL_H
#include "Component.h"

#include <SDL.h>


namespace cwing{ 

class Ball : public Component 
{
public:

    static Ball* getInstance(int x, int y, int w, int h);
    void draw() const;
    //void tick();
    ~Ball();
protected:
		Ball(int x, int y, int w, int h);

private:
    SDL_Texture* ball_tex;
    
};
}

#endif