#pragma once

#include "graphics/sprite.h"

#include <memory>
#include <string>

#include "graphics/font.h"
#include "graphics/fontbuffer.h"

namespace Graphics
{
    /**
     * @brief Text sprite controller
     * @details Rendered with Font class text string as sprite
     */
    class Text : public Sprite
    {
    protected:
        /// Pointer to font
        std::shared_ptr<Font> p_font;

        /// Font color
        SDL_Color m_color;

        /// Text string
        std::string m_text;

        /// Font name
        std::string font_name;

        /// Updates texture (re-render if needed)
        void update();

    public:
        /// Default constructor is not provided
        Text() = delete;

        /**
         * @brief Constructor-initializer
         * @param renderer Renderer
         * @param font Pointer to font to render with
         * @param x Coordinate X value
         * @param y Coordinate Y value
         * @param text Text string (UTF-8)
         * @param color Font color
         */
        Text(SDL_Renderer* renderer, std::shared_ptr<Font> font, int x, int y, const std::string& text = "", SDL_Color color = { 255, 255, 255, 255 });

        /// Destructor
        ~Text();

        /**
         * @brief Getter for font
         * @return Pointer to font
         */
        std::shared_ptr<Graphics::Font> font() const;

        /**
         * @brief Getter for text string
         * @return Rendered text string (in UTF-8)
         */
        const std::string& text() const;

        /**
         * @brief Getter for font colot
         * @return Font color
         */
        SDL_Color color() const;


        /**
         * @brief Setter for text string
         * @param text New text string (in UTF-8) to render
         */
        void setText(const std::string& text);

        /**
         * @brief Setter for text size
         * @param font_size New font size
         */
        void setFontSize(int font_size);

        /// Resets sprite size (if modified)
        void resetSize();


        /// Renders text sprite
        virtual void render();
    };
}
