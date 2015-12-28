#include "Sprite.h"

Sprite::Sprite()
{
    firstFrame = 0;
    lastFrame = 0;
    delay = 0;
    currentFrame = 0;
    image = NULL;
    delayCounter = 0;
}

Sprite::~Sprite()
{

}

void Sprite::setImage(Image* i)
{
    image = i;
}

Image* Sprite::getImage()
{
    return image;
}

void Sprite::update()
{
    delayCounter++;

    if(delayCounter > delay)
    {
        delayCounter = 0;
        currentFrame++;
    }

    if(currentFrame > lastFrame)
        currentFrame = firstFrame;
}

void Sprite::render(int x, int y, Graphics g)
{
    if(image != NULL)
    {
        image->render(x , y, currentFrame, g);
    }
}

void Sprite::setAnimation(int f, int l, int d)
{
    firstFrame = f;
    lastFrame = l;
    delay = d;
    //delayCounter = 0;
}

void Sprite::setFrame(int frame)
{
    currentFrame = firstFrame = lastFrame = frame;
    delay = 0;
    delayCounter = 0;
}

int Sprite::getWidth()
{
    if(image == NULL)
    {
        return -1;
    }
    else
    {
        return image->getFrameWidth();
    }
}

int Sprite::getHeight()
{
    if(image == NULL)
    {
        return -1;
    }
    else
    {
        return image->getFrameHeight();
    }
}

void Sprite::resetCounter()
{
    delayCounter = 0;
}