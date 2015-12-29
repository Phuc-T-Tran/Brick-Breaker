#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

class Input
{
public:
    Input();
    ~Input();

    void update();
    
    // Keyboard
    bool keyDown(SDL_Scancode key);
    bool keyHit(SDL_Scancode key);
    bool keyUp(SDL_Scancode key);

    // Joystick


    // Mouse
    bool mouseDown(int key);
    bool mouseClicked(int key);
    bool mouseUp(int key);
    int getMouseX();
    int getMouseY();
    void setMousePos(int x, int y);
    void hideCursor(bool hide = true);
    
    static const int MOUSE_LEFT = 0;
    static const int MOUSE_RIGHT = 1;
    static const int MOUSE_MIDDLE = 2;

private:
    // Keyboard
    int numKeys;
    bool* currKeys;
    bool* prevKeys;

    // Joystick
    int numJoysticks;
    SDL_Joystick** joysticks;

    // Mouse
    int mouseX, mouseY;
    bool currClicks[3];
    bool prevClicks[3];
};

#endif