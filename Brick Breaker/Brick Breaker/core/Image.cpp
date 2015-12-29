#include "Image.h"

#include <SDL_image.h>
#include <iostream>
#include <SDL.h>

Image::Image(SDL_Texture* texture) : texture(texture), alpha(255), xScale(1), yScale(1)
{
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

Image::~Image()
{
    // ResourceManager will free the texture
}

void Image::render(int x, int y, Graphics g)
{
    if (texture == NULL)
        return;

    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = width * xScale;
    destRect.h = height * yScale;

    SDL_SetTextureAlphaMod(texture, alpha);
    SDL_RenderCopy(g.getRenderer(), texture, NULL, &destRect);
}

//void Image::render(int x, int y, int frame, Graphics g)
//{
//    SDL_Rect destRect;
//    destRect.x = x;
//    destRect.y = y;
//    destRect.w = frameWidth;
//    destRect.h = frameHeight;
//
//    int columns = width / frameWidth;
//
//    SDL_Rect sourceRect;
//    sourceRect.x = (frame % columns)*frameWidth;
//    sourceRect.y = (frame / columns)*frameHeight;
//    sourceRect.w = frameWidth;
//    sourceRect.h = frameHeight;
//
//    SDL_RenderCopy(g.getRenderer(), texture, &sourceRect, &destRect);
//}

int Image::getWidth()
{
    return width;
}

int Image::getHeight()
{
    return height;
}

void Image::setTexture(SDL_Texture* texture)
{
    this->texture = texture;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

bool Image::loaded()
{
    return texture != NULL;
}

void Image::setAlpha(int alpha)
{
    this->alpha = alpha;
    if (this->alpha < 0)
        this->alpha = 0;
    if (this->alpha > 255)
        this->alpha = 255;
}
void Image::incAlpha(int amount)
{
    setAlpha(alpha + amount);
}
void Image::decAlpha(int amount)
{
    setAlpha(alpha - amount);
}

void Image::setScale(float scale)
{
    xScale = scale;
    yScale = scale;
}
//int Image::getFrameWidth()
//{
//    return frameWidth;
//}
//
//int Image::getFrameHeight()
//{
//    return frameHeight;
//}
//
//void Image::setFrameSize(int w, int h)
//{
//    frameWidth = w;
//    frameHeight = h;
//}
//
//bool Image::isLoaded()
//{
//    return (texture != NULL);
//}
//
//void Image::setColor()
//{
//    if (texture != NULL)
//    {
//        SDL_SetTextureColorMod(texture, r, g, b);
//    }
//}
//
//void Image::setColor(Uint8 r, Uint8 g, Uint8 b)
//{
//    if (texture != NULL)
//    {
//        SDL_SetTextureColorMod(texture, r, g, b);
//    }
//}