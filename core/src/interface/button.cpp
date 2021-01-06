#include "core/interface/button.h"

namespace Interface
{
    Button::Button(
        SDL_Renderer* renderer,
        const std::string& path_default,
        const std::string& path_clicked,
        const std::string& path_hovered,
        const std::string& path_disabled
    ) : sprites { Graphics::Sprite(renderer, path_default),
            Graphics::Sprite(renderer, path_clicked), Graphics::Sprite(renderer, path_hovered),
                Graphics::Sprite(renderer, path_disabled) }
    {
        state = State::Default;
    }

    Button::Button(SDL_Renderer* renderer, const std::string& path_default, const std::string& path_clicked) :
        sprites{ Graphics::Sprite(renderer, path_default), Graphics::Sprite(renderer, path_clicked),
            Graphics::Sprite(renderer, path_default), Graphics::Sprite(renderer, path_default) }

    {
        state = State::Default;
    }

    void Button::setState(State new_state)
    {
        state = new_state;
    } 

    void Button::setX(int x)
    {
        for (auto& sprite : sprites)
            sprite.setX(x);
        geometry.x = x;
    }

    void Button::setY(int y)
    {
        for (auto& sprite : sprites)
            sprite.setY(y);
        geometry.y = y;
    }

    void Button::setHeight(unsigned height)
    {
        for (auto& sprite : sprites)
            sprite.setHeight(height);
        geometry.height = height;
    }

    void Button::setWidth(unsigned width)
    {
        for (auto& sprite : sprites)
            sprite.setWidth(width);
        geometry.width = width;
    }

    bool Button::onControl(Control::VirtualGamepad::KeyCode code)
    {
        switch (code)
        {
        case Control::VirtualGamepad::A:
            onClick();
            return true;
        default:
            return false;
        }
    }

    void Button::onClick()
    {
        return;
    }

    void Button::render()
    {
        sprites[state].render();
    }
}
