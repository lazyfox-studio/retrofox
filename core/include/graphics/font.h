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
        TTF_Font* font;

    public:
        Font() = delete;
        explicit Font(const std::string& ttf_path, int font_size);
        ~Font();

        std::shared_ptr<Graphics::Texture> renderText(SDL_Renderer* renderer, const std::string& text, SDL_Color color);
    };
}
