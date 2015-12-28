#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <map>

class Input
{
public:
    static const int MOUSE_LEFT = 1;
    static const int MOUSE_MIDDLE = 2;
    static const int MOUSE_RIGHT = 3;

    Input();
    ~Input();

    void update();
    
    bool keyDown(SDL_Scancode key);
    bool keyHit(SDL_Scancode key);
    bool keyUp(SDL_Scancode key);

    //bool mouseDown(int key);
    //bool mouseClicked(int key);
    //bool mouseUp(int key);
    //int getMouseX();
    //int getMouseY();
    void setMousePos(int x, int y);
    void hideCursor(bool hide = true);

private:
    int numKeys;
    bool* currKeys;
    bool* prevKeys;
};

#endif