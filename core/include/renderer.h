#pragma once

#include <SDL.h>

class Renderer
{
protected:
    SDL_Renderer* renderer;

public:
    Renderer();
    ~Renderer();
};
