#pragma once

struct Rectangle
{
public:
    Rectangle(float x=-1, float y=-1, int width=-1, int height=-1);
    ~Rectangle();

    float left();
    float right();
    float top();
    float bot();

    float centerX();
    float centerY();

    void setLeft(float i);
    void setRight(float i);
    void setTop(float i);
    void setBot(float i);

    bool overlaps(Rectangle rect);
    bool contains(float x, float y);

    float x, y;
    int width, height;
};