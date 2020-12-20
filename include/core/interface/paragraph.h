#pragma once

#include "interface/widget.h"

#include <string>
#include <vector>

#include <SDL.h>

#include "graphics/text.h"

namespace Interface
{
    /**
     * @brief Paragraph - multiline text widget
     * @details Class to represent text label with more than one line of text
     */
    class Paragraph : public Widget
    {
    protected:
        /// Text strings (separated to lines according to available width)
        std::vector<std::string> m_lines;

        /// Text sprites (according to m_lines)
        std::vector<Graphics::Text> m_sprites;

        /// Line spacing (distance between lines in pixels)
        int m_line_spacing;


        /**
         * @brief Organizes text and explodes it into strings vector
         * @param font Pointer to font
         * @param text Long text string
         * @param max_width Maximal widget width
         * @param word_wrap True if word wrapping needed
         */
        void organizeTextLines(std::shared_ptr<Graphics::Font> font, const std::string& text, unsigned max_width, bool word_wrap = true);

        /**
         * @brief Renders organized text lines
         * @param renderer Renderer
         * @param font Font to render with
         */
        void renderTextLines(SDL_Renderer* renderer, std::shared_ptr<Graphics::Font> font);

    public:
        /// Default constructor is not provided
        Paragraph() = delete;

        /**
         * @brief Constructor-initializer
         * @param renderer Renderer
         * @param font Pointer to font to render with
         * @param x Coordinate X value
         * @param y Coordinate Y value
         * @param max_width Maximal widget width
         * @param text Test string
         * @param color Font color
         */
        Paragraph(SDL_Renderer* renderer, std::shared_ptr<Graphics::Font> font,  int x, int y, unsigned max_width, const std::string& text, SDL_Color color = { 255, 255, 255, 255 });
        
        /// Destructor
        ~Paragraph();


        /// Renders text paragraph via provided renderer
        virtual void render();
    };
}
