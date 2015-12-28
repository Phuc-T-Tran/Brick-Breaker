#include "Paddle.h"

#include "Constants.h"
#include <iostream>

Paddle::Paddle(ResourceManager& resources) :
image(resources.getTexture("paddle"))
{
    rect = { (float)GameConstants::GAME_WIDTH / 2 - image.getWidth() / 2,
        (float)GameConstants::GAME_HEIGHT - 3 * image.getHeight(),
        image.getWidth(),
        image.getHeight() };
}


Paddle::~Paddle()
{
}

void Paddle::update(Input& input)
{
    if (input.keyDown(SDL_SCANCODE_A) ||
        input.keyDown(SDL_SCANCODE_LEFT))
        rect.x -= PaddleConstants::SPEED;
    if (input.keyDown(SDL_SCANCODE_D) ||
        input.keyDown(SDL_SCANCODE_RIGHT))
        rect.x += PaddleConstants::SPEED;

    //TODO: clamp(value,min,max)
    //      multiple calls to thing.getThing() is bad
    if (rect.x < 0)
        rect.x = 0;
    if (rect.x + image.getWidth() > GameConstants::GAME_WIDTH)
        rect.x = GameConstants::GAME_WIDTH - image.getWidth();
}

void Paddle::render(Graphics& graphics)
{
    image.render(rect.x, rect.y, graphics);
}

Rectangle& Paddle::getRect()
{
    return rect;
}

int Paddle::getX()
{
    return rect.x;
}

int Paddle::getY()
{
    return rect.y;
}

int Paddle::getWidth()
{
    return rect.width;
}

int Paddle::getHeight()
{
    return rect.height;
}