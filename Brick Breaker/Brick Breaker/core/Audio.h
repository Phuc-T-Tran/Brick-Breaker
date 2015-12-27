#pragma once
#include <SDL_mixer.h>

class Audio
{
public:
    bool init();
    void kill();
    bool musicPlaying();
    bool musicPaused();
    void pauseMusic();
    void resumeMusic();
    void stopMusic();
    void stopChannel(int channel);
};