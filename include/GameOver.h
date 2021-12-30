#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "Component.h"
#include <SDL.h>


namespace cwing{ 

class GameOver : public Component 
{
public:

    static GameOver* getInstance(int x, int y, int w, int h);
    void draw() const;
    void tick();
    ~GameOver();
    //bool quitGame(){return }
   
   
    bool gameOver(){ return false;}
    bool getEndGame(){return endGame;} 
    
    
protected:
		GameOver(int x, int y, int w, int h);

private:
    SDL_Texture* gameOver_tex;
    bool endGame = false;
  
};
}

#endif