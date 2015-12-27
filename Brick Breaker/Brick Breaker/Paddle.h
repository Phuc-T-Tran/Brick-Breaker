#ifndef PADDLE_H
#define PADDLE_H

#include "core/ResourceManager.h"
#include "core/Image.h"
#include "core/Input.h"
#include "core/Rectangle.h"

class Paddle
{
public:
    Paddle(ResourceManager& resources);
    ~Paddle();

    void update(Input& input);
    void render(Graphics& graphics);

    Rectangle& getRect();
    int getX();
    int getY();
    int getWidth();
    int getHeight();

private:
    Rectangle rect;
    Image image;
};

#endif