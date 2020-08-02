#include "window.h"

Window::Window()
{
    window = SDL_CreateWindow("Retrofox", 100, 100, 800, 600, SDL_WINDOW_HIDDEN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Window::show()
{
    SDL_ShowWindow(window);
}

void Window::start()
{
    Graphics::Sprite sprite(renderer, "D:/Source/retrofox/core/data/testsprite.bmp");

    SDL_Event event;
    while (true)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return;
            }
        }

        SDL_RenderClear(renderer);
        sprite.render();
        SDL_RenderPresent(renderer);
    }
}