#pragma once

#include "interface/widget.h"
#include "graphics/font.h"

#include <string>
#include <memory>

namespace Interface
{
    class Label : public Widget
    {
    protected:
        Graphics::Font* p_font;
        std::shared_ptr<Graphics::Texture> p_texture;
        Graphics::Sprite m_sprite;
        std::string m_text;
        SDL_Color m_color;

        void updateSprite(SDL_Renderer* renderer = nullptr);
    public:
        Label() = delete;
        Label(SDL_Renderer* renderer, Graphics::Font* font, const std::string& text = "", SDL_Color color = { 255, 255, 255, 255 });
    
        virtual void setX(int x);
        virtual void setY(int y);
        virtual void setHeight(unsigned height);
        virtual void setWidth(unsigned width);
        
        virtual void render();
    };
}
