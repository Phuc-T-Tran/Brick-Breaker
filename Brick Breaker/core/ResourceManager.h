#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>

struct Mix_Chunk;
struct SDL_Texture;
class Graphics;

class ResourceManager
{
public:
    ResourceManager(Graphics* graphics);
    ~ResourceManager();

    void loadTexture(std::string name, std::string filepath);
    SDL_Texture* getTexture(std::string name);

    void loadSound(std::string name, std::string filePath);
    Mix_Chunk* getSound(std::string name);
    

private:
    Graphics* graphics;
    std::map<std::string, SDL_Texture*> textures;
    std::map<std::string, Mix_Chunk*> sounds;
};

#endif