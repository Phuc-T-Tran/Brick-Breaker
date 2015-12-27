#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "StateManager.h"
class Game;

class GameState
{
public:
    GameState(Game& game);
    virtual ~GameState();

    virtual void update() = 0;
    virtual void render() = 0;

    Game& getGame() { return game; }

protected:
    Game& game;
    StateManager& states;
};

#endif