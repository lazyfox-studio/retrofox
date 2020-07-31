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
        Graphics::Sprite sprites[4]; //TODO: Swap to std::vector

        /// Current button state
        State state;

    public:
        Button(
            const Graphics::Sprite& sprite_default, 
            const Graphics::Sprite& sprite_clicked, 
            const Graphics::Sprite& sprite_hovered, 
            const Graphics::Sprite& sprite_disabled
        );
        Button(const Graphics::Sprite& sprite_default, const Graphics::Sprite& sprite_clicked);
        ~Button() = default;

        virtual void setX(int x);
        virtual void setY(int y);
        virtual void setHeight(unsigned height);
        virtual void setWidth(unsigned width);

        void setState(State new_state);

        virtual void render(Renderer& renderer);
    };
}