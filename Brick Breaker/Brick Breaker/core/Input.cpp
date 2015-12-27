#include "Input.h"
#include <SDL.h>
#include <iostream>

Input::Input() : numKeys(0), prevKeys(NULL), currKeys(NULL)
{
    const Uint8* state = SDL_GetKeyboardState(&numKeys);
    prevKeys = new bool[numKeys];
    currKeys = new bool[numKeys];
    for (int i = 0; i < numKeys; i++)
    {
        prevKeys[i] = false;
        currKeys[i] = false;
    }
}

Input::~Input()
{
    delete[] prevKeys;
    delete[] currKeys;
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

void Input::setMousePos(int x, int y)
{
    SDL_WarpMouseInWindow(NULL, x, y);
}

void Input::hideCursor(bool hide)
{
    SDL_ShowCursor(!hide);
}
