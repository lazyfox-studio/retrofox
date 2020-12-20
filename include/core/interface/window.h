#pragma once

#include <memory>
#include <string>

#include "SDL.h"

#include "control/virtualgamepad.h"
#include "interface/widget.h"

namespace Interface
{
    /**
     * @brief System window
     * @details Class to represent window
     */
    class Window
    {
    protected:
        /// Pointer to window data
        SDL_Window* window;

        /// Pointer to renderer
        SDL_Renderer* renderer;
        
        /// Window geometry
        SDL_Rect geometry;

        /// Pointer to root widget
        std::shared_ptr<Interface::Widget> root_widget;

    public:
        /// Default constructor is not provided
        Window() = delete;

        /**
         * @brief Constructor-initializer
         * @details Creates window and renderer as SDL objects
         * @param title Window title
         * @param x Coordinate X value
         * @param y Coordinate Y value
         * @param width Width value
         * @param height Height value
         */
        Window(const std::string& title, int x, int y, int width, int height);

        /// Destructor
        ~Window();

        
        /// Initializes window
        virtual void initialize();

        /// Gets window into full-screen mode
        void setFullscreen();

        /// Lets window display
        void show();

        /// Starts application loop
        void start();
    };
}
