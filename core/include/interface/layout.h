#pragma once

#include "interface/widget.h"

#include <list>

namespace Interface
{
    using WidgetRefList = std::list<std::reference_wrapper<Interface::Widget>>;

    /**
     * @brief Contains widgets
    */
    class Layout : public Widget
    {
    protected:
        WidgetRefList widgets;

    public:
        struct Margin
        {
            int left;
            int top;   
            int right;
            int bottom;
        };
        Margin margin;

        struct Spacing
        {
            int vertical;
            int horizontal;
        };
        Spacing spacing;

        enum class Stacking
        {
            Vertical,
            Horizontal
        };
        Stacking stacking;

        Layout();
        Layout(int x, int y, unsigned height, unsigned width);
        ~Layout();

        void pushFront(Widget& widget);
        void pushBack(Widget& widget);
        virtual void render();

        void update();
    };
}
