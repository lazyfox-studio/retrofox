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

    SDL_Texture* Graphics::Font::renderText(SDL_Renderer* renderer, const std::string& text, SDL_Color color)
    {
        SDL_Surface* surf = TTF_RenderText_Blended(font, text.c_str(), color);
        if (surf == nullptr) 
        {
            TTF_CloseFont(font);
            throw std::exception("Cannot surfacerize font!");
            return nullptr;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
        if (texture == nullptr) 
        {
            throw std::exception("Cannot texturize font!");
        }
        SDL_FreeSurface(surf);
        return texture;
    }
}
