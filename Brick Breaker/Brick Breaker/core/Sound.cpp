#include "Sound.h"

Sound::Sound(Mix_Chunk* sound) : sound(sound)
{
}

Sound::~Sound()
{
}

int Sound::play(int loops)
{
    if (sound != NULL)
        return Mix_PlayChannel(-1, sound, loops);
    else
        return -1;
}

bool Sound::isLoaded()
{
    return (sound != NULL);
}
