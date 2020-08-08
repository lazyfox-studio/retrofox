#pragma once

#include "interface/widget.h"

#include <memory>
#include <string>

#include <SDL.h>

#include "graphics/font.h"
#include "graphics/text.h"

namespace Interface
{
    class Label : public Widget
    {
    protected:
        Graphics::Text m_text;

    public:
        Label() = delete;
        Label(SDL_Renderer* renderer, Graphics::FontPtr font, int x, int y, const std::string& text = "");
        ~Label();

        virtual void setHeight(unsigned height);
        virtual void setWidth(unsigned width);

        virtual void render();
    };
}