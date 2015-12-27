#include "ResourceManager.h"

#include "Image.h"
#include <iostream>
#include <SDL_image.h>
#include <iostream>

ResourceManager::ResourceManager(Graphics* graphics) : graphics(graphics)
{
}


ResourceManager::~ResourceManager()
{
    for (std::map<std::string, SDL_Texture*>::iterator it = textures.begin(); it != textures.end(); it++)
        SDL_DestroyTexture((*it).second);
}

SDL_Texture* ResourceManager::getTexture(std::string name)
{
    if (!textures[name])
        std::cout << "ResourceManager::getTexture(): Could not find [" + name + "]." << std::endl;
    return textures[name];
}

void ResourceManager::loadTexture(std::string name, std::string filepath)
{
    SDL_Texture* texture = NULL;
    SDL_Surface* loadedSurface = NULL;
    loadedSurface = IMG_Load(filepath.c_str());

    if (loadedSurface != NULL)
    {
        // Pink -> Transparent
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0, 0xFF));
        texture = SDL_CreateTextureFromSurface(graphics->getRenderer(), loadedSurface);

        if (texture != NULL)
        {
            //width = loadedSurface->w;
            //height = loadedSurface->h;
            //SDL_GetTextureColorMod(texture, &r, &g, &b);
            SDL_FreeSurface(loadedSurface);
        }
        else
            std::cout << "Failed to load image: " << filepath << std::endl;
    }
    else
        std::cout << "Failed to load image: " << filepath << std::endl;

    textures[name] = texture;
}