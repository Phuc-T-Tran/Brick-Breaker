#pragma once
#include <math.h>

template<class T> struct Vector2
{
    Vector2(T x=0, T y=0) : x(x), y(y) {}
    ~Vector2(){}
    
    Vector2& operator +=(Vector2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2& operator -=(Vector2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2& operator *(T scale)
    {
        x *= scale;
        y *= scale;
        return *this;
    }

    Vector2& operator *=(T scale)
    {
        x *= scale;
        y *= scale;
        return *this;
    }

    void rotate(float degrees)
    {
        float radians = degrees * M_PI / 180.0f;
        float newX, newY;
        newX = x * cos(radians) - y * sin(radians);
        newY = x * sin(radians) + y * cos(radians);
        x = newX;
        y = newY;
    }

    T x, y;
};

