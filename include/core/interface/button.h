#pragma once

#include "core/interface/widget.h"

#include <array>

#include <SDL.h>

namespace Interface
{
    /**
     * @brief Button widget
     * @details Class to represent 'clickable' button
     */
    class Button : public Widget
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
        /**
         * @brief Constructor-initializer (with each state)
         * @param renderer Renderer
         * @param path_default Path to texture for default button state
         * @param path_clicked Path to texture for clicked button state
         * @param path_hovered Path to texture for hovered button state
         * @param path_disabled Path to texture for disabled button state
         */
        Button(
            SDL_Renderer* renderer,
            const std::string& path_default,
            const std::string& path_clicked,
            const std::string& path_hovered,
            const std::string& path_disabled
        );

        /**
         * @brief Constructor-initializer (with important states only)
         * @param renderer Renderer
         * @param path_default Path to texture for default button state
         * @param path_clicked Path to texture for clicked button state
         */
        Button(SDL_Renderer* renderer, const std::string& path_default, const std::string& path_clicked);
        
        /// Default destructor
        ~Button() = default;

        /**
         * @brief Setter for coordinate X value
         * @param x New coordinate X value
         */
        virtual void setX(int x);

        /**
         * @brief Setter for coordinate Y value
         * @param y New coordinate Y value
         */
        virtual void setY(int y);

        /**
         * @brief Setter for height value
         * @param height New height value
         */
        virtual void setHeight(unsigned height);

        /**
         * @brief Setter for width value
         * @param width New width value
         */
        virtual void setWidth(unsigned width);

        /**
         * @brief Setter for button state value
         * @param new_state New state value
         */
        void setState(State new_state);

        virtual bool onControl(Control::VirtualGamepad::KeyCode code);

        virtual void onClick();

        /// Renders button via provided renderer
        virtual void render();
    };
}
