#include "core/graphics/font.h"

namespace Graphics
{
    bool Font::initialized = false;

    void Font::calculateAverageCharWidth()
    {
        m_average_char_width = static_cast<float>(calculateTextWidth("jiwmhx ote")) / 10.f;
    }

    Font::Font(const std::string& ttf_path, int font_size)
        : c_path(ttf_path)
    {
        if (!initialized)
        {
            if (TTF_Init() != 0)
            {
                throw std::runtime_error("Font module cannot be initialized...");
                SDL_Quit();
            }
            initialized = true;
        }
        p_font = TTF_OpenFont(ttf_path.c_str(), font_size);
        if (p_font == nullptr)
            throw std::runtime_error("Font file cannot be opened...");
        calculateAverageCharWidth();
    }

    Font::~Font()
    {
        TTF_CloseFont(p_font);
    }

    std::string Font::path() const
    {
        return c_path;
    }

    float Font::averageCharWidth() const
    {
        return m_average_char_width;
    }

    unsigned Font::calculateTextWidth(const std::string& text)
    {
        int width = 0;
        if (TTF_SizeUTF8(p_font, text.c_str(), &width, nullptr))
            throw std::runtime_error("Cannot calculate text width (invalid glyphs found)!");
        return static_cast<unsigned>(width);
    }

    SDL_Rect Font::calculateTextRect(const std::string& text)
    {
        int width = 0, height = 0;
        if (TTF_SizeUTF8(p_font, text.c_str(), &width, &height))
            throw std::runtime_error("Cannot calculate text rect (invalid glyphs found)!");
        return { 0, 0, width, height };
    }

    std::shared_ptr<Graphics::Texture> Graphics::Font::renderText(SDL_Renderer* renderer, const std::string& text, SDL_Color color)
    {
        SDL_Surface* surface = TTF_RenderUTF8_Blended(p_font, text.c_str(), color);
        auto texture = std::make_shared<Graphics::Texture>(renderer, surface);
        SDL_FreeSurface(surface);
        return texture;
    }
}
