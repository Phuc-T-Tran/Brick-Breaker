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
    if (game.getInput().keyHit(SDL_SCANCODE_ESCAPE))
    {
        states.popState();
        return;
    }
    else if (game.getInput().keyHit(SDL_SCANCODE_SPACE))
    {
        PlayState* ps = new PlayState(game);
        StateManager* newStates = &(game.getStates());
        Game& newGame = game;
        states.changeState(ps);
        newStates->addState(new TransitionState(newGame, ps));
        return;
    }

    for (std::vector<Ball*>::iterator it = balls.begin();
        it != balls.end(); it++)
        (*it)->idleBounce();
}

void TitleState::render()
{
    background.render(0, 0, game.getGraphics());

    for (std::vector<Ball*>::iterator it = balls.begin();
        it != balls.end(); it++)
        (*it)->render(game.getGraphics());

    //TODO: Color class / structure?
    title.render("Brick Breaker", GameConstants::GAME_WIDTH / 2,
        150, 142, 234, 170, game.getGraphics());
    message.render("Press Space", GameConstants::GAME_WIDTH / 2,
        350, 142, 234, 170, game.getGraphics());
}