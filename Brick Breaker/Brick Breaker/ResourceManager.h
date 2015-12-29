#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>
#include "Image.h"
#include "Graphics.h"

class ResourceManager
{
public:
    ResourceManager(Graphics* graphics);
    ~ResourceManager();

    void loadImage(std::string name, std::string filepath);
    Image* getImage(std::string name);

private:
    Graphics* graphics;
    std::map<std::string, Image*> images;
};

#endif