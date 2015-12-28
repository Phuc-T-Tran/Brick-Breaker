#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(float x, float y, int width, int height) :
    x(x), y(y), width(width), height(height)
{
}

Rectangle::~Rectangle()
{
}

float Rectangle::left()
{
    return x;
}
float Rectangle::right()
{
    return x + width;
}
float Rectangle::top()
{
    return y;
}
float Rectangle::bot()
{
    return y + height;
}

void Rectangle::setLeft(float i)
{
    x = i;
}
void Rectangle::setRight(float i)
{
    x = i - width;
}
void Rectangle::setTop(float i)
{
    y = i;
}
void Rectangle::setBot(float i)
{
    y = i - height;
}

float Rectangle::centerX()
{
    return x + width / 2;
}

float Rectangle::centerY()
{
    return y + height / 2;
}

bool Rectangle::overlaps(Rectangle rect)
{
    if(right() <= rect.left())
        return false;

    if (left() >= rect.right())
        return false;

    if (top() >= rect.bot())
        return false;

    if(bot() <= rect.top())
        return false;

    return true;
}

bool Rectangle::contains(float x, float y)
{
    if(x >= left() && x <= right() && y >= top() && y <= bot())
        return true;

    return false;
}

