#pragma once

#include <memory>
#include <string>

#include "SDL.h"

#include "control/virtualgamepad.h"
#include "interface/widget.h"

namespace Interface
{
    class Window
    {
    protected:
        SDL_Window* window;
        SDL_Renderer* renderer;

        std::shared_ptr<Interface::Widget> root_widget;

    public:
        Window() = delete;
        Window(std::string title, int x, int y, int width, int height);
        ~Window();

        virtual void initialize();

        void setFullscreen();

        /**
         * @brief Show window
        */
        void show();
        /**
         * @brief Start application loop
        */
        void start();

    };
}