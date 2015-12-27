#include "LoseState.h"

#include "core/Game.h"
#include "Constants.h"
#include "TitleState.h"

LoseState::LoseState(Game& game)
    : GameState(game), background(game.getResources().getTexture("plain")),
    text("data/fonts/Roboto-Regular.ttf", 48)
{
}


LoseState::~LoseState()
{
}

void LoseState::update()
{
    if (game.getInput().keyHit(SDL_SCANCODE_ESCAPE))
        states.changeState(new TitleState(game));
}

void LoseState::render()
{
    background.render(0, 0, game.getGraphics());
    text.render("Game Over",
        GameConstants::GAME_WIDTH/2,
        GameConstants::GAME_HEIGHT/3,
        255, 255, 255, game.getGraphics());
}