#ifndef GAME_H
#define GAME_H

#include "StateManager.h"
#include "ResourceManager.h"

#include "Graphics.h"
#include "Input.h"
#include "Audio.h"

class Game
{
public:
    Game(char* title, int w_width, int w_height, bool fullscreen = false);
    virtual ~Game();

    void run();
    void update();
    void render();

    StateManager& getStates();
    Graphics& getGraphics();
    Input& getInput();
    ResourceManager& getResources();

protected:
    StateManager states;
    ResourceManager resources;

    Graphics graphics;
    Input input;
    //Audio audio;

    const int FPS = 60;
    const int DELAY = 1000 / FPS;
	bool running;
};

#endif