#include "interface/menu.h"

namespace Interface
{
    Menu::Menu() : Widget()
    {
        current = widgets.begin();
        first = widgets.begin();
        last = widgets.begin();
    }

    Menu::Menu(int x, int y, unsigned height, unsigned width, unsigned button_height) : Widget(x, y, height, width),
        layout(x, y, height, width)
    {
        current = widgets.begin();
        first = widgets.begin();
        last = widgets.begin();
        m_button_height = button_height;
        visible_buttons_count = (layout.height() - layout.margin.top - layout.margin.bottom) /
            (m_button_height + layout.spacing.vertical);
    }

    Menu::~Menu()
    {
        widgets.clear();
    }

    void Menu::reset()
    {
        current = widgets.begin();
        (*current)->setState(Button::State::Hovered);
        first = widgets.begin();
        last = widgets.begin();
        for (size_t i = 0; (i < visible_buttons_count) && (last != widgets.end()); i++)
        {
            last++;
        }
        layout.clear();
        for (auto i = first; i != last; ++i)
        {
            layout.pushBack(*i);
        }
    }

    void Menu::pushFront(std::shared_ptr<Button> button)
    {
        button->base_size.height = m_button_height;
        button->size_policy.vertical = Interface::Button::SizePolicy::Fixed;
        widgets.push_front(button);
    }

    void Menu::pushBack(std::shared_ptr<Button> button)
    {
        button->base_size.height = m_button_height;
        button->size_policy.vertical = Interface::Button::SizePolicy::Fixed;
        widgets.push_back(button);
    }

    bool Menu::next()
    {
        if (current == --widgets.end())
        {
            return false;
        }
        if (current == last)
        {
            layout.popFront();
            last++;
            (*current)->setState(Button::State::Default);
            current++;
            (*current)->setState(Button::State::Hovered);
            layout.pushBack(*last);
            return true;
        }
        else
        {
            (*current)->setState(Button::State::Default);
            current++;
            (*current)->setState(Button::State::Hovered);
            return true;
        }
    }

    bool Menu::previous()
    {
        if (current == widgets.begin())
        {
            return false;
        }
        if (current == first)
        {
            layout.popBack();
            first--;
            (*current)->setState(Button::State::Default);
            current--;
            (*current)->setState(Button::State::Hovered);
            layout.pushFront(*first);
            return true;
        }
        else
        {
            (*current)->setState(Button::State::Default);
            current--;
            (*current)->setState(Button::State::Hovered);
            return true;
        }
    }

    void Menu::setActive()
    {
        if (widgets.begin() != widgets.end())
        {
            (*current)->setState(Interface::Button::State::Hovered);
        }
    }

    void Menu::setInactive()
    {
        if (widgets.begin() != widgets.end())
        {
            (*current)->setState(Interface::Button::State::Default);
        }
    }

    void Menu::setX(int x)
    {
        geometry.x = x;
        layout.setX(x);
        layout.update();
    }

    void Menu::setY(int y)
    {
        geometry.y = y;
        layout.setY(y);
        layout.update();
    }

    void Menu::setHeight(unsigned height)
    {
        geometry.height = height;
        layout.setHeight(height);
        layout.update();
    }

    void Menu::setWidth(unsigned width)
    {
        geometry.width = width;
        layout.setWidth(width);
        layout.update();
    }

    bool Menu::onControl(Control::VirtualGamepad::KeyCode code)
    {
        if ((*current)->onControl(code))
        {
            return true;
        }
        else
        {
            switch (code)
            {
            case Control::VirtualGamepad::Up:
                return previous();
            case Control::VirtualGamepad::Down:
                return next();
            case Control::VirtualGamepad::A:
                // current->get().onClick();
                return true;
            default:
                return false;
            }
        }
    }

    void Menu::render()
    {
        layout.render();
    }
}
