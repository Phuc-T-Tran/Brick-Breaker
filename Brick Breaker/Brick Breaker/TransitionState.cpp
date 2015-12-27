#include "TransitionState.h"

#include "PlayState.h"
#include "Constants.h"
#include <sstream>
#include <iostream>
#include <iomanip>

TransitionState::TransitionState(Game& game, PlayState* playState)
    : GameState(game), playState(playState),
    image(playState->getResources().getTexture("transition")),
    text("data/fonts/Roboto-Regular.ttf",32),
    duration(GameConstants::TRANSITION_DURATION)
{
    image.setAlpha(0);
    text.alpha = 0;
}


TransitionState::~TransitionState()
{
}

void TransitionState::update()
{
    duration--;
    
    // Fade in, then fade out during last quarter
    if (duration > GameConstants::TRANSITION_DURATION * 3/4)
    {
        image.incAlpha(8);
        text.alpha += 8;
    }
    else if (duration <= GameConstants::TRANSITION_DURATION * 1/4)
    {
        image.decAlpha(4);
        text.alpha -= 4;
    }

    playState->update();

    if (duration <= 0)
        states.popState();
}

void TransitionState::render()
{
    playState->render();

    int imageX = GameConstants::GAME_WIDTH / 2 - image.getWidth() / 2;
    int imageY = BrickConstants::HEIGHT * 3;
    image.render(imageX,imageY,game.getGraphics());
        
    std::stringstream ss;
    ss << "Level " << playState->getLevel();
    text.render(ss.str(),
        imageX + image.getWidth() / 2,
        imageY + image.getHeight() / 2,
        255,255,255,game.getGraphics());
}