#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "core/GameState.h"
#include "core/Image.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "HUD.h"
#include "core/Game.h"

class PlayState : public GameState
{
public:
    PlayState(Game& game);
    ~PlayState();

    void loadLevel();

    void update();
    void render();

    void loseLife() { lives--; }
    void gainLife() { lives++; }
    int getLives() { return lives; }
    int getLevel() { return level; }
    Paddle& getPaddle() { return paddle; }
    std::vector<Brick*>& getBricks() { return bricks; }
    ResourceManager& getResources() { return game.getResources(); }

private:
    Image background;
    Paddle paddle;
    Ball ball;
    HUD hud;
    std::vector<Brick*> bricks;
    int level;
    int lives;
};

#endif