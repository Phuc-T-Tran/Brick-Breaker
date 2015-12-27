#include "GameState.h"

#include "Game.h"

GameState::GameState(Game& game) : game(game), states(game.getStates())
{
}

GameState::~GameState()
{
}