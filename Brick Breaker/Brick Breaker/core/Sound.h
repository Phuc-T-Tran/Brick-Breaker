#pragma once
#include "Audio.h"

class Sound
{
private:
    Mix_Chunk* sound;
public:
    Sound();
    ~Sound();
    bool load(char* fileName);
    void free();
    int play(int loops = 0);
    bool isLoaded();
};

