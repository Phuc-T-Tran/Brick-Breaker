#include "BrickBreaker.h"

#include "TitleState.h"
#include "Constants.h"

BrickBreaker::BrickBreaker() : Game("Brick Breaker", GameConstants::GAME_WIDTH, GameConstants::GAME_HEIGHT)
{
    graphics.setIcon("data/icon/icon16.png");
    resources.loadTexture("bg1", "data/backgrounds/bg1.png");
    resources.loadTexture("bg2", "data/backgrounds/bg2.png");
    resources.loadTexture("paddle", "data/sprites/paddle.png");
    resources.loadTexture("ball", "data/sprites/ball.png");
    resources.loadTexture("brick1", "data/sprites/brick1.png");
    resources.loadTexture("brick2", "data/sprites/brick2.png");
    resources.loadTexture("brick3", "data/sprites/brick3.png");
    resources.loadTexture("transition", "data/sprites/transition.png");
    resources.loadTexture("plain", "data/backgrounds/plain.png");

    input.hideCursor();
    states.addState(new TitleState(*this));
}

BrickBreaker::~BrickBreaker()
{
}