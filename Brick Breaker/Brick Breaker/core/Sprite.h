#ifndef SPRITE_H
#define SPRITE_H

#include "Image.h"

class Sprite
{
public:
    Sprite(Image* image);
    Sprite();
    ~Sprite();
    void setImage(Image* image);

    Image* getImage();
    void update();
    void render(int x, int y, Graphics g);
    void setAnimation(int f, int l, int d);
    void setFrame(int f);
    void resetCounter();

    int getWidth();
    int getHeight();

private:
    Image* image;
    int firstFrame;
    int lastFrame;
    int delay;
    int currentFrame;
    int delayCounter;
};

#endif