#pragma once

#include "core/GameState.h"
#include "core/Image.h"
#include "core/Text.h"

class LoseState : public GameState
{
public:
    LoseState(Game& game);
    ~LoseState();

    void update();
    void render();

private:
    Image background;
    Text text;
};

