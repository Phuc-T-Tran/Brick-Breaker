#include "PauseState.h"

#include "core/Game.h"
#include "Constants.h"

PauseState::PauseState(Game& game)
    : GameState(game),
    text("data/fonts/Roboto-Regular.ttf",48)
{
    text.alpha = 200;
}

PauseState::~PauseState()
{
}

void PauseState::update()
{
    if (game.getInput().keyHit(SDL_SCANCODE_ESCAPE))
        states.popState();
}

void PauseState::render()
{
    if (states.second())
        states.second()->render();

    game.getGraphics().drawFillRect(0, 0,
        GameConstants::GAME_WIDTH,
        GameConstants::GAME_HEIGHT,
        0, 0, 0, 80);
    
    text.render("Paused", GameConstants::GAME_WIDTH / 2,
        GameConstants::GAME_HEIGHT / 2,255,255,255,game.getGraphics());
}