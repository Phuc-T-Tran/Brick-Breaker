#include "Input.h"

Input::Input() : numKeys(0), prevKeys(NULL), currKeys(NULL), numJoysticks(0)
{
    const Uint8* state = SDL_GetKeyboardState(&numKeys);
    prevKeys = new bool[numKeys];
    currKeys = new bool[numKeys];
    for (int i = 0; i < numKeys; i++)
    {
        prevKeys[i] = false;
        currKeys[i] = false;
    }

    numJoysticks = SDL_NumJoysticks();
    joysticks = new SDL_Joystick*[numJoysticks];
    for (int i = 0; i < numJoysticks; i++)
    {
        joysticks[i] = SDL_JoystickOpen(i);
    }
}

Input::~Input()
{
    delete[] prevKeys;
    delete[] currKeys;

    for (int i = 0; i < numJoysticks; i++)
    {
        SDL_JoystickClose(joysticks[i]);
        delete joysticks[i];
    }
    delete[] joysticks;
}

void Input::update()
{
    const Uint8* newKeys = SDL_GetKeyboardState(&numKeys);

    // Set prevKeys to currKeys
    for (int i = 0; i < numKeys; i++)
    {
        prevKeys[i] = currKeys[i];
        currKeys[i] = newKeys[i];
    }

    SDL_JoystickUpdate();

    Uint32 mouseButton = SDL_GetMouseState(&mouseX, &mouseY);
    for (int i = 0; i < 3; i++)
        prevClicks[i] = currClicks[i];
    currClicks[MOUSE_LEFT] = ((mouseButton & SDL_BUTTON_LMASK) == mouseButton);
    currClicks[MOUSE_RIGHT] = ((mouseButton & SDL_BUTTON_RMASK) == mouseButton);
    currClicks[MOUSE_MIDDLE] = ((mouseButton & SDL_BUTTON_MMASK) == mouseButton);
}

bool Input::keyDown(SDL_Scancode key)
{
    if (key < 0 || key > numKeys) return false;
    return currKeys[key];
}

bool Input::keyHit(SDL_Scancode key)
{
    if (key < 0 || key > numKeys) return false;
    return (currKeys[key] && !prevKeys[key]);
}

bool Input::keyUp(SDL_Scancode key)
{
    if (key < 0 || key > numKeys) return false;
    return (prevKeys[key] && !currKeys[key]);
}

bool Input::mouseDown(int key)
{
    return currClicks[key];
}

bool Input::mouseClicked(int key)
{
    return (!prevClicks[key] && currClicks[key]);
}

bool Input::mouseUp(int key)
{
    return (prevClicks[key] && !currClicks[key]);
}

void Input::setMousePos(int x, int y)
{
    SDL_WarpMouseInWindow(NULL, x, y);
}

void Input::hideCursor(bool hide)
{
    SDL_ShowCursor(!hide);
}
