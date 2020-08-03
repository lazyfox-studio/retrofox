#include "interface/button.h"

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
        geometry.x = x;
        for (size_t i = 0; i < sprites.size() ; i++)
        {
            sprites[i].setX(x);
        }
    }

    void Button::setY(int y)
    {
        geometry.y = y;
        for (size_t i = 0; i < sprites.size(); i++)
        {
            sprites[i].setY(y);
        }
    }

    void Button::setHeight(unsigned height)
    {
        geometry.height = height;
        for (size_t i = 0; i < sprites.size(); i++)
        {
            sprites[i].setHeight(height);
        }
    }

    void Button::setWidth(unsigned width)
    {
        geometry.width = width;
        for (size_t i = 0; i < sprites.size(); i++)
        {
            sprites[i].setWidth(width);
        }
    }

    void Button::render()
    {
        sprites[state].render();
    }
}
