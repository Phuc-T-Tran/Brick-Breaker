#pragma once

#include "core/ResourceManager.h"
#include "core/Rectangle.h"
#include "core/Image.h"

class Brick
{
public:
    Brick(ResourceManager& resources, int x, int y, int health);
    ~Brick();

    void damage();
    void render(Graphics& graphics);

    bool isDead() { return health <= 0; }
    Rectangle& getRect() { return rect; }

private:
    Image image;
    Rectangle rect;
    ResourceManager& resources;

    int health;
};

