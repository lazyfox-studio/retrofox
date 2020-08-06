#pragma once

#include "graphics/sprite.h"

#include <memory>
#include <string>

#include "graphics/font.h"
#include "graphics/fontbuffer.h"

namespace Graphics
{
    class Text : public Sprite
    {
    protected:
        FontPtr p_font;
        SDL_Color m_color;

        std::string font_name;

        void update();

    public:
        Text() = delete;
        Text(SDL_Renderer* renderer, FontPtr font, const std::string& text = "", SDL_Color color = { 255, 255, 255, 255 });
        ~Text();

        virtual void render();

        void resetSize();

        void setText(const std::string& text);
        void setFontSize(int font_size);
    };
}
