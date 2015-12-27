#pragma once
#include <SDL_ttf.h>
#include "Graphics.h"
#include <string>

//TODO: Fix this god awful class.

class Text
{
public:
    Text(std::string filePath, int size = 12);
    ~Text();
    void render(std::string text, int x, int y, int r, int g, int b, Graphics& graphics);
    void setSize(int size);
    void getDimensions(std::string text, int* width, int* height);

    int alpha;

private:
    TTF_Font* font;
    std::string filePath;
    int size;
};