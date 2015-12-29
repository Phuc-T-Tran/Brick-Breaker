#include "PlayState.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include "core\Game.h"
#include "Constants.h"
#include "TransitionState.h"
#include "PauseState.h"
#include "LoseState.h"
#include "TitleState.h"

PlayState::PlayState(Game& game)
    : GameState(game),
    background(game.getResources().getTexture("bg2")),
    paddle(game.getResources()),
    ball(this),
    hud(*this),
    level(GameConstants::START_LEVEL),
    lives(GameConstants::START_LIVES)
{
    loadLevel();
}

PlayState::~PlayState()
{
    for (std::vector<Brick*>::iterator it = bricks.begin();
        it != bricks.end(); it++)
    {
        delete (*it);
    }
}

void PlayState::loadLevel()
{
    ball.setOnPaddle();

    std::stringstream ss;
    std::string line;
    ss << "data/levels/level" << level << ".txt";
    std::fstream file;
    file.open(ss.str());
    
    if (file.good())
    {
        int x = BrickConstants::WIDTH;
        int y = BrickConstants::HEIGHT*2;
        int health = 0;
        while (getline(file, line))
        {
            ss.clear();
            ss.str(line);
            while (ss >> health)
            {
                Brick* brick = new Brick(game.getResources(), x, y, health);
                bricks.push_back(brick);
                x += BrickConstants::WIDTH;
            }
            x = BrickConstants::WIDTH;
            y += BrickConstants::HEIGHT;
        }
        file.close();
    }
    else
        std::cout << "PlayState::loadLevel(): Failed to load " + ss.str() + "." << std::endl;
}

void PlayState::update()
{
    if (game.getInput().keyHit(SDL_SCANCODE_ESCAPE))
    {
        states.addState(new PauseState(game));
        return;
    }

    paddle.update(game.getInput());
    ball.update(game.getInput());

    if (lives <= 0)
    {
        states.addState(new LoseState(game, *this));
        return;
    }
    if (bricks.empty())
    {
        if (level == GameConstants::MAX_LEVEL)
        {
	        TitleState* ts = new TitleState(game);
            states.changeState(ts);
	    }
        else
        {
            level++;
            lives = GameConstants::START_LIVES;
            loadLevel();
            states.addState(new TransitionState(game, this));
        }
    }
}

void PlayState::render()
{
    background.render(0, 0, game.getGraphics());
    paddle.render(game.getGraphics());
    ball.render(game.getGraphics());
    for (std::vector<Brick*>::iterator it = bricks.begin();
        it != bricks.end(); it++)
    {
        (*it)->render(game.getGraphics());
    }
    hud.render(game.getGraphics());
}
