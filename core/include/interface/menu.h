#pragma once

#include "interface/widget.h"

#include "interface/button.h"
#include "interface/layout.h"

namespace Interface
{
    class Menu : public Widget
    {
    protected:
        Interface::Layout layout;
        std::list<std::reference_wrapper<Interface::Button>> widgets;

        std::list<std::reference_wrapper<Interface::Button>>::iterator current;
        std::list<std::reference_wrapper<Interface::Button>>::iterator first;
        std::list<std::reference_wrapper<Interface::Button>>::iterator last;

        unsigned m_button_height;
        size_t visible_buttons_count;

    public:
        Menu();
        Menu(int x, int y, unsigned height, unsigned width, unsigned button_height);
        ~Menu();

        void reset();

        void pushFront(Button& widget);
        void pushBack(Button& widget);

        void next();
        void previous();

        virtual void setX(int x);
        virtual void setY(int y);
        virtual void setHeight(unsigned height);
        virtual void setWidth(unsigned width);

        virtual bool onControl(Control::VirtualGamepad::KeyCode code);

        virtual void render();
    };
}
