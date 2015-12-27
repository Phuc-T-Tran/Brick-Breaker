#include "Particle.h"

#include "Constants.h"

Particle::Particle(float x, float y)
    : position(x, y), startDuration(0),duration(0), alpha(0), angle(0)
{
    startDuration = rand() % ParticleConstants::MAX_DURATION + ParticleConstants::MIN_DURATION;
    duration = startDuration;
}


Particle::~Particle()
{
}

void Particle::update()
{
    duration--;
    if (duration > startDuration / 2)
        alpha+= 10;
    else
        alpha-= 10;
    angle++;
}

void Particle::render(Graphics& graphics)
{
    graphics.drawFillRect(position.x, position.y, 2, 2, 255, 255, 255, 120, angle);
}