#include "LoseState.h"

#include "core/Game.h"
#include "Constants.h"
#include "TitleState.h"

LoseState::LoseState(Game& game, PlayState& playState)
    : GameState(game), playState(playState),
    background(game.getResources().getTexture("plainBlack")),
    text("data/fonts/Roboto-Regular.ttf", 48)
{
    background.setAlpha(0);
    text.alpha = 200;
}


LoseState::~LoseState()
{
}

void LoseState::update()
{
    if (background.alpha < 180)
        background.incAlpha(6);
    if (game.getInput().keyHit(SDL_SCANCODE_ESCAPE))
    {
        StateManager& states = game.getStates();
        Game& game = this->game;
        states.popState();
        states.changeState(new TitleState(game));
    }
}

void LoseState::render()
{
    playState.render();
    background.render(0, 0, game.getGraphics());
    text.render("Game Over",
        GameConstants::GAME_WIDTH/2,
        GameConstants::GAME_HEIGHT/4,
        255, 255, 255, game.getGraphics());
}