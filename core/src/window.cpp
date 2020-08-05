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
    Interface::Button button(renderer, "../../core/data/testsprite.bmp", "../../core/data/testsprite2.bmp");
    Interface::Button button2(renderer, "../../core/data/testsprite.bmp", "../../core/data/testsprite2.bmp");

    Interface::Layout layout(5, 5, 400, 400);
    layout.pushBack(button);
    layout.pushBack(button2);

    Graphics::Font font("../../core/data/roboto-regular.ttf", 40);
    Graphics::Text label(renderer, &font, "Hello world");

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
        layout.render();
        label.render();
        SDL_RenderPresent(renderer);
    }
}