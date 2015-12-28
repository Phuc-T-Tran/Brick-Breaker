#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <string>

class Graphics
{
public:
    Graphics(const char* title, int w_width, int w_height, bool fullscreen);

    void clear();
    void update();
    int getWidth();
    int getHeight();
    SDL_Renderer* getRenderer();

    void drawRect(int x, int y, int width, int height, int r, int g, int b, int a = 255, float rot = 0);
    void drawFillRect(int x, int y, int width, int height, int r, int g, int b, int a = 255, float rot = 0);
    void drawLine(int x1, int y1, int x2, int y2);
    void setIcon(std::string filePath);
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif