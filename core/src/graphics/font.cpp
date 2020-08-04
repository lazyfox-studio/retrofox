#include "graphics/font.h"

namespace Graphics
{
    bool Font::initialized = false;

    Font::Font(const std::string& ttf_path, int font_size)
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
        font = TTF_OpenFont(ttf_path.c_str(), font_size);
        if (font == nullptr)
            throw std::exception("Font file cannot be opened...");
    }

    Font::~Font()
    {
        TTF_CloseFont(font);
    }

    std::shared_ptr<Graphics::Texture> Graphics::Font::renderText(SDL_Renderer* renderer, const std::string& text, SDL_Color color)
    {
        SDL_Surface* surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
        auto texture = std::make_shared<Graphics::Texture>(renderer, surface);
        SDL_FreeSurface(surface);
        return texture;
    }
}
