#include "Graphics.h"
#include <iostream>
#include <SDL_image.h>

Graphics::Graphics(const char* title, int w_width, int w_height, bool fullscreen)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    if (fullscreen)
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_width, w_height, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
    else
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_width, w_height, SDL_WINDOW_SHOWN);

    if (window == NULL)
        std::cout << "Window failed to initialize!" << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
        std::cout << "Renderer failed to initialize!" << std::endl;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // set draw color to solid black
    //SDL_RenderSetLogicalSize(renderer, g_width, g_height);
}

void Graphics::clear()
{
    SDL_RenderClear(renderer);
}

void Graphics::update()
{
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Graphics::getRenderer()
{
    return renderer;
}

void Graphics::drawRect(int x, int y, int width, int height, int r, int g, int b, int a, float rot)
{
    SDL_Rect destRect = { x, y, width, height };
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawRect(renderer,&destRect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // return to black
}

void Graphics::drawFillRect(int x, int y, int width, int height, int r, int g, int b, int a, float rot)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, r, g, b, a);
    SDL_Rect destRect = { x, y, width, height };
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_SetTextureAlphaMod(texture, a);
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
    //SDL_RenderCopyEx(renderer, texture, NULL, &destRect, rot, NULL,SDL_FLIP_NONE);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Graphics::setIcon(std::string filePath)
{
    SDL_Surface* icon = IMG_Load(filePath.c_str());//SDL_LoadBMP(filePath.c_str());
    if (!icon)
        std::cout << "Graphics::setIcon(): Could not load [" + filePath + "]." << std::endl;
    SDL_SetWindowIcon(window, icon);
    SDL_FreeSurface(icon);
}

void Graphics::drawLine(int x1, int y1, int x2, int y2)
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}