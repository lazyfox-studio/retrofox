#pragma once

#include "graphics/texture.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>
#include <memory>

namespace Graphics
{
    /**
     * @brief Font renderer
     * @details Class for rendering and calculating metrics of TrueType font
     */
    class Font
    {
    protected:
        /// True if SDL-ttf library is initialized
        static bool initialized;

        /// Font data pointer
        TTF_Font* p_font;

        /// Path to .ttf file
        const std::string c_path;

        /// Average char width (calculated by calculateAverageCharWidth() method)
        float m_average_char_width;

        /**
         * @brief Calculates average char width
         * @details This method is called in constructor. It saves calculated
         * value in m_average_char_width variable.
         * @note Width is calculated as an average width of symbol in string
         * "jiwmhx ote" (average width = total width / 10)
         */
        void calculateAverageCharWidth();


    public:
        /// Default constructor is not provided
        Font() = delete;

        /**
         * @brief Constructor-initializer
         * @param ttf_path Path to .ttf file with TrueType font
         * @param font_size Size of glyphs (in pixels) to load
         */
        Font(const std::string& ttf_path, int font_size);

        /// Destructor
        ~Font();


        /**
         * @brief Getter for string with path to loaded font file
         * @return Path to font file
         */
        std::string path() const;

        /**
         * @brief Getter for average character width
         * @details See calculateAverageCharWidth()
         * @return Average character width
         */
        float averageCharWidth() const;

        /**
         * @brief Calculates potential width of surface with given string
         * @details (No rendering)
         * @param text String to calculate width of
         * @return Width of surface with text
         */
        unsigned calculateTextWidth(const std::string& text);

        /**
         * @brief Calculates potential size of surface with given string
         * @details (No rendering)
         * @param text String to calculate size of
         * @return Rectangle with size of surface with text
         */
        SDL_Rect calculateTextRect(const std::string& text);


        /**
         * @brief Renders given text string as texture image
         * @param renderer Renderer
         * @param text Text string (UTF-8) to render
         * @param color Font color
         * @return Pointer to rendered texture
         */
        std::shared_ptr<Graphics::Texture> renderText(SDL_Renderer* renderer, const std::string& text, SDL_Color color);
    };
}
