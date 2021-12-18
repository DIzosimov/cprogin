#ifndef STARTGAME_H
#define STARTGAME_H
#include "Component.h"
#include <SDL.h>


namespace cwing{ 

class StartGame : public Component 
{
public:

    static StartGame* getInstance(int x, int y, int w, int h);
    void draw() const;
    void tick(){}
    ~StartGame();
    void mouseDown(const SDL_Event& eve);
    void mouseUp(const SDL_Event& eve);
     bool startGame(){ return isDown ;}
   
  
    
    
    
protected:
		StartGame(int x, int y, int w, int h);

private:
    SDL_Texture* startGame_tex;
    bool isDown = false;
  
};
}

#endif