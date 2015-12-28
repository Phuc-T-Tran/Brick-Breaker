#pragma once
#include "Audio.h"

class Sound
{
public:
    Sound(Mix_Chunk* sound);
    ~Sound();
    int play(int loops = 0);
    bool isLoaded();

private:
    Mix_Chunk* sound;
};

