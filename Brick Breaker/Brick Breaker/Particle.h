#pragma once

#include "core/Vector2.h"
#include "core/Graphics.h"

class Particle
{
public:
    Particle(float x, float y);
    ~Particle();

    void update();
    void render(Graphics& graphics);

    bool isDead() { return duration <= 0; }

private:
    Vector2<float> position;
    Vector2<float> velocity;
    int startDuration;
    int duration;
    int alpha;
    float angle;
};

