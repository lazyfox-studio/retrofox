#pragma once

#include <SDL.h>

#include "graphics/sprite.h"

class Window
{
protected:
    SDL_Window* window;
    SDL_Renderer* renderer;
    
public:
    Window();
    ~Window();

    /**
     * @brief Show window
    */
    void show();
    /**
     * @brief Start application loop
    */
    void start();
};
