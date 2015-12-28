#pragma once

#include "core/Image.h"
#include "core/Graphics.h"
#include "core/Input.h"
#include "core/Rectangle.h"
#include "core/Vector2.h"
#include <vector>
#include "core/ResourceManager.h"
#include "core/Sound.h"
//#include "PlayState.h";

class PlayState;

class Ball
{
public:
    Ball(PlayState* playState);
    Ball(ResourceManager& resources);
    ~Ball();

    void setOnPaddle();

    // Bounce around the screen
    void idleBounce();

    void update(Input& input);
    void render(Graphics& graphics);

    int getX();
    int getY();
    bool isOffScreen();

private:
    PlayState* playState;
    bool onPaddle;
    Rectangle rect;
    Vector2<float> velocity;
    Image image;
    Sound bounce;
};