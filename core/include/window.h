#pragma once

#include <SDL.h>

#include "interface/button.h"
#include "interface/layout.h"
#include "interface/label.h"

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
