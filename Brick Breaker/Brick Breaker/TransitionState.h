#pragma once

#include "core/GameState.h"
#include "core/Image.h"
#include "core/Text.h"

class PlayState;

// Display an overlay over the PlayState
class TransitionState : public GameState
{
public:
    TransitionState(Game& game, PlayState* playState);
    ~TransitionState();

    void update();
    void render();

private:
    PlayState* playState;
    Image image;
    Text text;
    int duration; // In ms
};

