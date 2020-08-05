#pragma once

#include "graphics/sprite.h"

#include <memory>
#include <string>

#include "graphics/font.h"

namespace Graphics
{
    class Label : public Sprite
    {
    protected:
        Graphics::Font* p_font;
        std::string m_text;
        SDL_Color m_color;

        void update();

    public:
        Label() = delete;
        Label(SDL_Renderer* renderer, Graphics::Font* font, const std::string& text = "", SDL_Color color = { 255, 255, 255, 255 });
        ~Label();

        void setText(const std::string& text);
    };
}
