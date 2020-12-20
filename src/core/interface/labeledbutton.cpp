#include "core/interface/labeledbutton.h"

namespace Interface
{
    LabeledButton::LabeledButton(
        SDL_Renderer* renderer,
        const std::string& text,
        const std::string& path_default,
        const std::string& path_clicked,
        const std::string& path_hovered,
        const std::string& path_disabled
    ) : Button(renderer, path_default, path_clicked, path_hovered, path_disabled),
        label(renderer, Graphics::FontBuffer::instance().load("../../core/data/roboto-regular.ttf", 0), 0, 0, text)
    {
        
    }
    LabeledButton::LabeledButton(
        SDL_Renderer* renderer, 
        const std::string& text, 
        const std::string& path_default,
        const std::string& path_clicked
    ) : Button(renderer, path_default, path_clicked),
        label(renderer, Graphics::FontBuffer::instance().load("../../core/data/roboto-regular.ttf", 0), 0, 0, text)
    {

    }

    void LabeledButton::setX(int x)
    {
        for (auto& sprite : sprites)
            sprite.setX(x);
        geometry.x = x;
        label.setX(x);
    }

    void LabeledButton::setY(int y)
    {
        for (auto& sprite : sprites)
            sprite.setY(y);
        geometry.y = y;
        label.setY(y);
    }

    void LabeledButton::setHeight(unsigned height)
    {
        for (auto& sprite : sprites)
            sprite.setHeight(height);
        geometry.height = height;
        label.setHeight(height);

    }

    void LabeledButton::setWidth(unsigned width)
    {
        for (auto& sprite : sprites)
            sprite.setWidth(width);
        geometry.width = width;
        label.setWidth(width);
    }

    void LabeledButton::render()
    {
        sprites[state].render();
        label.render();
    }
}
