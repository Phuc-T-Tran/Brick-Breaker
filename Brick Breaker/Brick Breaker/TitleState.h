#ifndef TITLESTATE_H
#define TITLESTATE_H

#include "core/GameState.h"
#include "core/Image.h"
#include "core/Text.h"
#include "Ball.h"
//#include "Particle.h"

class TitleState : public GameState
{
public:
    TitleState(Game& game);
    ~TitleState();

    void update();
    void render();

private:
    Image background;
    Text title;
    Text message;
    //Particle particle;

    std::vector<Ball*> balls;
};

#endif