#pragma once

#include "core/GameState.h"
#include "core/Image.h"
#include "core/Text.h"
#include "PlayState.h"

class LoseState : public GameState
{
public:
    LoseState(Game& game, PlayState& playState);
    ~LoseState();

    void update();
    void render();

private:
    PlayState& playState;
    Image background;
    Text text;
};

