#include "StateManager.h"

#include "GameState.h"

void StateManager::addState(GameState* s)
{
    states.push_back(s);
}

void StateManager::changeState(GameState* s)
{
    popState();
    addState(s);
}

void StateManager::popState()
{
    std::vector<GameState*>::iterator it = states.end() - 1;
    delete *it;
    states.erase(it);
}

void StateManager::update()
{
    if (!states.empty() && states.back() != NULL)
        states.back()->update();
}

void StateManager::render()
{
    if (!states.empty() && states.back() != NULL)
        states.back()->render();
}

bool StateManager::isEmpty()
{
    return states.empty();
}

GameState* StateManager::back()
{
    return states.back();
}

GameState* StateManager::second()
{
    if (!isEmpty())
    {
        std::vector<GameState*>::iterator it = states.end() - 1;
        if (it != states.begin())
            it--;

        return *it;
    }
    else
        return NULL;
}