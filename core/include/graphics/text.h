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
        std::string m_text;

        std::string font_name;

        void update();

    public:
        Text() = delete;
        Text(SDL_Renderer* renderer, FontPtr font, int x, int y, const std::string& text = "", SDL_Color color = { 255, 255, 255, 255 });
        ~Text();

        std::shared_ptr<Graphics::Font> font() const;
        const std::string& text() const;
        SDL_Color color() const;

        void setText(const std::string& text);
        void setFontSize(int font_size);
        void resetSize();

        virtual void render();
    };
}
