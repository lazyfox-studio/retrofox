#include "interface/window.h"

namespace Interface
{
    Window::Window(const std::string& title, int x, int y, int width, int height)
    {
        window = SDL_CreateWindow(title.c_str(), 100, 100, width, height,  SDL_WINDOW_HIDDEN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        geometry = { x, y, width, height };
    }

    Window::~Window()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);

        root_widget.reset();
    }

    void Window::initialize()
    {

    }

    void Window::setFullscreen()
    {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    }

    void Window::show()
    {
        SDL_ShowWindow(window);
    }

    void Window::start()
    {
        SDL_Event event;
        while (true)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    return;
                }
                else
                {
                    Control::VirtualGamepad::KeyCode key_code = Control::VirtualGamepad::instance().processInput(event);
                    if (key_code != Control::VirtualGamepad::KeyCode::Empty)
                    {
                        root_widget->onControl(key_code);
                    }
                }
            }

            SDL_RenderClear(renderer);
            root_widget->render();
            SDL_RenderPresent(renderer);
        }
    }
}
