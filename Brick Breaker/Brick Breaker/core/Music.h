#pragma once
#include <SDL_mixer.h>

class Music
{
public:
    Music();
    ~Music();
    bool load(char fileName[]);
    void free();
    void play(int loops = 0);
    bool isLoaded();

private:
    Mix_Music* music;
};