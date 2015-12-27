#include "TitleState.h"

#include <iostream>
#include "core\Game.h"
#include "PlayState.h"
#include "Constants.h"
#include "TransitionState.h"

TitleState::TitleState(Game& game)
    : GameState(game),
    background(game.getResources().getTexture("bg1")),
    title("data/fonts/Roboto-Regular.ttf", 64),
    message("data/fonts/Roboto-Regular.ttf", 24)//,particle(10, 10)
{
    for (int i = 0; i < GameConstants::NUM_TITLE_BALLS; i++)
    {
        Ball* ball = new Ball(game.getResources());
        balls.push_back(ball);
    }
}

TitleState::~TitleState()
{
}

void TitleState::update()
{
    //particle.update();

    for (std::vector<Ball*>::iterator it = balls.begin();
        it != balls.end(); it++)
        (*it)->idleBounce();

    if (game.getInput().keyHit(SDL_SCANCODE_ESCAPE))
        states.popState();
    else if (game.getInput().keyHit(SDL_SCANCODE_SPACE))
    {
        PlayState* ps = new PlayState(game);
        StateManager* newStates = &states;
        states.changeState(ps);
        newStates->addState(new TransitionState(game, ps));
    }
}

void TitleState::render()
{
    background.render(0, 0, game.getGraphics());
    //particle.render(game.getGraphics());

    for (std::vector<Ball*>::iterator it = balls.begin();
        it != balls.end(); it++)
        (*it)->render(game.getGraphics());

    title.render("Brick Breaker", GameConstants::GAME_WIDTH / 2,
        100, 255, 255, 255, game.getGraphics());
    message.render("<Press Space>", GameConstants::GAME_WIDTH / 2,
        350, 255, 255, 255, game.getGraphics());


    /*game.getGraphics().drawFillRect(0, 0, GameConstants::GAME_WIDTH,
        480, 0, 0, 0, 200);*/

        /*game.getGraphics().drawFillRect(0, 0,
        GameConstants::GAME_WIDTH,
        GameConstants::GAME_HEIGHT,
        255, 23, 55, 200);*/
}