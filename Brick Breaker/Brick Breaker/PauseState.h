#pragma once

#include "core/GameState.h"
#include "core/Image.h"
#include "core/Text.h"

class PauseState : public GameState
{
public:
    PauseState(Game& game);
    ~PauseState();

    void update();
    void render();

private:
    Text text;
};

