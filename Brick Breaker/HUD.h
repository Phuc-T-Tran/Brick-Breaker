#pragma once

#include "core/Image.h"
#include "core/Graphics.h"
//#include "PlayState.h";

class PlayState;

class HUD
{
public:
    HUD(PlayState& playState);
    ~HUD();

    void render(Graphics& g);

private:
    Image lives;
    PlayState& playState;
};

