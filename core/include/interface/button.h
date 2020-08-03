#pragma once

#include "interface/widget.h"

#include <array>

#include <SDL.h>

namespace Interface
{
    /**
     * @brief Clickable button
    */
    class Button : Widget
    {
    public:
        /// Available button states
        enum State
        {
            Default,  ///< Default state
            Clicked,  ///< Clicked state
            Hovered,  ///< Hovered state
            Disabled  ///< Disabled state
        };

    protected:
        /// Array of sprites for each state
        std::array<Graphics::Sprite, 4> sprites;

        /// Current button state
        State state;

    public:
        Button(
            SDL_Renderer* renderer,
            const std::string& path_default,
            const std::string& path_clicked,
            const std::string& path_hovered,
            const std::string& path_disabled
        );
        Button(SDL_Renderer* renderer, const std::string& path_default, const std::string& path_clicked);
        ~Button() = default;

        virtual void setX(int x);
        virtual void setY(int y);
        virtual void setHeight(unsigned height);
        virtual void setWidth(unsigned width);

        void setState(State new_state);

        virtual void render();
    };
}