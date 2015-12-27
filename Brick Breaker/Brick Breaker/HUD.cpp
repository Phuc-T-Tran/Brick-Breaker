#include "HUD.h"

#include "Constants.h"
#include "PlayState.h"

HUD::HUD(PlayState& playState)
    : playState(playState),
    lives(playState.getResources().getTexture("ball"))
{
}

HUD::~HUD()
{
}

void HUD::render(Graphics& graphics)
{
    for (int i = 0; i < playState.getLives(); i++)
        lives.render(10 + (30 * i), 10, graphics);
}