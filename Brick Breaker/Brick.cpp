#include "Brick.h"

#include "Constants.h"
#include <sstream>
#include <iostream>

Brick::Brick(ResourceManager& resources, int x, int y, int health)
    : image(resources.getTexture("brick1")),
    rect(x,y,BrickConstants::WIDTH, BrickConstants::HEIGHT),
    health(health),
    resources(resources)
{
    std::stringstream ss;
    ss << "brick" << health;
    image.setTexture(resources.getTexture(ss.str()));
}

Brick::~Brick()
{
}

void Brick::damage()
{
    health--;
    if (health > 0)
    {
        std::stringstream ss;
        ss << "brick" << health;
        image.setTexture(resources.getTexture(ss.str()));
        //TODO: Move all the brick textures into one .png
    }
}

void Brick::render(Graphics& graphics)
{
    if (health > 0)
        image.render(rect.x, rect.y, graphics);
}