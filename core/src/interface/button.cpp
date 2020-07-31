#include "interface/button.h"

namespace Interface{
    Button::Button(const Graphics::Sprite& sprite_default,
        const Graphics::Sprite& sprite_clicked, const Graphics::Sprite& sprite_hovered,
        const Graphics::Sprite& sprite_disabled)
        : state(Default),
        sprites{ sprite_default, sprite_clicked, sprite_hovered, sprite_disabled }
    {
    }

    Button::Button(const Graphics::Sprite& sprite_default, const Graphics::Sprite& sprite_clicked)
        : Button(sprite_default, sprite_clicked, sprite_default, sprite_default)
    {
    }

    void Button::setState(State new_state)
    {
        state = new_state;
    }

    void Button::render(Renderer& renderer)
    {
        renderer.draw(sprites + static_cast<int>(state));
    }

    void Button::setX(int x)
    {
        geometry.x = x;
        for (size_t i = 0; i < 4; i++)
        {
            sprites[i].setX(x);
        }
    }

    void Button::setY(int y)
    {
        geometry.y = y;
        for (size_t i = 0; i < 4; i++)
        {
            sprites[i].setY(y);
        }
    }

    void Button::setHeight(unsigned height)
    {
        geometry.height = height;
        for (size_t i = 0; i < 4; i++)
        {
            sprites[i].setHeight(height);
        }
    }

    void Button::setWidth(unsigned width)
    {
        geometry.width = width;
        for (size_t i = 0; i < 4; i++)
        {
            sprites[i].setWidth(width);
        }
    }
}
