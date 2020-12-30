#pragma once

#include "core/interface/widget.h"

#include <memory>
#include <string>

#include <SDL.h>

#include "core/graphics/font.h"
#include "core/graphics/text.h"

namespace Interface
{
    /**
     * @brief Text label widget
     * @details Class to represent label with text
     * @todo Font color management
     */
    class Label : public Widget
    {
    protected:
        /// Text sprite
        Graphics::Text m_text;

    public:
        /// Default constructor is not provided
        Label() = delete;

        /**
         * @brief Constructor-initializer
         * @param renderer Renderer
         * @param font Pointer to font
         * @param x Coordinate X value
         * @param y Coordinate Y value
         * @param text Text string (UTF-8)
         */
        Label(SDL_Renderer* renderer, std::shared_ptr<Graphics::Font> font, int x, int y, const std::string& text = "");
        
        /// Destructor
        ~Label();

        /**
         * @brief Setter for X coordinate value
         * @param x New X coordinate value
         */
        virtual void setX(int x);

        /**
         * @brief Setter for Y coordinate value
         * @param y New Y coordinate value
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

        /// Renders label via provided renderer
        virtual void render();
    };
}
