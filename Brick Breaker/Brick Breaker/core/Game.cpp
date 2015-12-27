#include "Game.h"
#include <iostream>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <time.h>

Game::Game(char* title, int w_width, int w_height, bool fullscreen) :
    graphics(title, w_width, w_height, fullscreen), resources(&graphics)
{
    TTF_Init();

    running = true;

    srand(time(NULL));
}

Game::~Game()
{
    TTF_Quit();
    SDL_Quit();
}

void Game::run()
{
    int frameStart = 0;
    int frameEnd = 0;

    while (running)
    {
        SDL_Event event;
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event))
        {
            switch (event.type) {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDL_SCANCODE_ESCAPE)
                    running = false;
                break;
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
            }
        }

        input.update();
        update();
        render();
        frameEnd = SDL_GetTicks() - frameStart;
        if (frameEnd < DELAY)
            SDL_Delay(DELAY - frameEnd);
    }
}


void Game::update()
{
    if (!states.isEmpty())
        states.update();
}

void Game::render()
{
    graphics.clear();
    if (!states.isEmpty())
        states.render();
    graphics.update();

    if (states.isEmpty())
        running = false;
}

Graphics& Game::getGraphics()
{
    return graphics;
}

Input& Game::getInput()
{
    return input;
}

StateManager& Game::getStates()
{
    return states;
}

ResourceManager& Game::getResources()
{
    return resources;
}