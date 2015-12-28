#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>
#include <string>
#include "Graphics.h"

class Image
{
public:
    Image(SDL_Texture* texture);
    ~Image();

    void render(int x, int y, Graphics graphics);
    //void render(int x, int y, int frame, Graphics g);

    int getWidth();
    int getHeight();
    void setTexture(SDL_Texture* texture);
    bool loaded();
    void setAlpha(int alpha);
    void incAlpha(int amount = 1);
    void decAlpha(int amount = 1);
    //int getFrameWidth();
    //int getFrameHeight();
    //void setFrameSize(int w, int h);

    //void setColor();
    //void setColor(Uint8 r, Uint8 g, Uint8 b);

    int alpha;

private:
    SDL_Texture* texture;
    int width;
    int height;
    //int alpha;
    //int frameWidth;
    //int frameHeight;
};

#endif