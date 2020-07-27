#pragma once

#include "interface/widget.h"

#include <list>

namespace Interface
{
    using WidgetList = std::list<Interface::Widget*>;

    /**
     * @brief Contains widgets
    */
    class Layout : public Widget
    {
    protected:
        WidgetList widgets;

    public:
        struct Margin
        {
            int left;
            int top;   
            int right;
            int bottom;
        };
        Margin margin;

        enum class Stacking
        {
            Vertical,
            Horizontal,
            GridVerical,
            GridHorizontal
        };
        Stacking stacking;

        Layout();
        Layout(int x, int y, unsigned height, unsigned width);
        ~Layout();

        virtual void render(Renderer& renderer);

    };
}