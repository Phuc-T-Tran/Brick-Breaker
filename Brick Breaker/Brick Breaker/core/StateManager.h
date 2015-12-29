#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <vector>

class GameState;

class StateManager
{
public:
    StateManager(){};
    ~StateManager(){};

    void addState(GameState* s);
    void changeState(GameState* s);
    void popState();
    void update();
    void render();
    bool isEmpty();

    GameState* back();

    // Returns the GameState directly beneath back()
    GameState* second();

private:
    std::vector<GameState*> states;
};

#endif