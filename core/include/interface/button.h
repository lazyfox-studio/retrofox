#pragma once

#include "interface/widget.h"

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
        Graphics::Sprite sprites[4];

        /// Current button state
        State state;

    public:
        Button(
            const Graphics::Sprite& sprite_default, 
            const Graphics::Sprite& sprite_clicked, 
            const Graphics::Sprite& sprite_hovered, 
            const Graphics::Sprite& sprite_disabled
        );
        ~Button() = default;

        void setState(State new_state);

        virtual void render(Renderer& renderer);
    };
}