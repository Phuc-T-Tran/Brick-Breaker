#include "Text.h"
#include <iostream>

Text::Text(std::string filePath, int size)
    : filePath(filePath), size(size), alpha(255)
{
    font = TTF_OpenFont(filePath.c_str(), size);
    if (font == NULL)
        std::cout << "Text::Text(): Failed to load font [" + filePath + "]" << std::endl;
}

Text::~Text()
{
    if (font != NULL)
        TTF_CloseFont(font);
}

void Text::render(std::string text, int x, int y, int r, int g, int b, Graphics& graphics)
{
    //TODO: This is wasteful creating/deleting.
    //      Move into ResourceManager and call only once.
    //      ...but might not work if we have variable strings.
    //      i.e "Level 1", "Level 2", etc. How do we load
    //      each of these only once? Is it possible?
    if (font == NULL) return;

    int width, height;
    TTF_SizeText(font, text.c_str(), &width, &height);
    SDL_Color color = { r, g, b };
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Texture* texture = NULL;

    if (surface == NULL)
        std::cout << "Text::render(): Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
    else
    {
        texture = SDL_CreateTextureFromSurface(graphics.getRenderer(), surface);

        if (texture == NULL)
            std::cout << "Unable to create texture from rendered text! SDL Error: " << TTF_GetError() << std::endl;
        
        if (alpha > 255)
            alpha = 255;
        else if (alpha < 0)
            alpha = 0;
        SDL_SetTextureAlphaMod(texture, alpha);
    }

    SDL_Rect destRect = { x - width/2, y-height/2, surface->w, surface->h };
    SDL_RenderCopy(graphics.getRenderer(), texture, NULL, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Text::setSize(int size)
{
    if (size == this->size)
        return;

    if (font != NULL)
        TTF_CloseFont(font);
    
    TTF_OpenFont(filePath.c_str(), size);

    if (font == NULL)
        std::cout << "Text::Text(): Failed to load font [" + filePath + "]" << std::endl;
}

void Text::getDimensions(std::string text, int* width, int* height)
{
    TTF_SizeText(font, text.c_str(), width, height);
}