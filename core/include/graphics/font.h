#pragma once

#include "graphics/texture.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>
#include <memory>

namespace Graphics
{
    class Font
    {
    protected:
        static bool initialized;
        TTF_Font* p_font;
        const std::string c_path;
        float m_average_char_width;

        void calculateAverageCharWidth();

    public:
        Font() = delete;
        explicit Font(const std::string& ttf_path, int font_size);
        ~Font();

        std::string path() const;
        float averageCharWidth() const;

        unsigned calculateTextWidth(const std::string& text);
        SDL_Rect calculateTextRect(const std::string& text);

        std::shared_ptr<Graphics::Texture> renderText(SDL_Renderer* renderer, const std::string& text, SDL_Color color);
    };
}
