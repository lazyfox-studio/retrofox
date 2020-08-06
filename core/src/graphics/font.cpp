#include "graphics/font.h"

namespace Graphics
{
    bool Font::initialized = false;

    Font::Font(const std::string& ttf_path, int font_size)
        : c_path(ttf_path)
    {
        if (!initialized)
        {
            if (TTF_Init() != 0)
            {
                throw std::exception("Font module cannot be initialized...");
                SDL_Quit();
            }
            initialized = true;
        }
        p_font = TTF_OpenFont(ttf_path.c_str(), font_size);
        if (p_font == nullptr)
            throw std::exception("Font file cannot be opened...");
    }

    Font::~Font()
    {
        TTF_CloseFont(p_font);
    }

    std::string Font::path()
    {
        return c_path;
    }

    unsigned Font::calculateTextWidth(const std::string& text)
    {
        int width = 0;
        if (TTF_SizeUTF8(p_font, text.c_str(), &width, nullptr))
            throw std::exception("Cannot calculate text width (invalid glyphs found)!");
        return static_cast<unsigned>(width);
    }

    SDL_Rect Font::calculateTextRect(const std::string& text)
    {
        int width = 0, height = 0;
        if (TTF_SizeUTF8(p_font, text.c_str(), &width, &height))
            throw std::exception("Cannot calculate text rect (invalid glyphs found)!");
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
