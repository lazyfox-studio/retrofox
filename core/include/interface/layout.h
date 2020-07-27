#pragma once

#include "interface/widget.h"

namespace Interface
{
    /**
     * @brief Contains widgets
    */
    class Layout : public Widget
    {
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
    };
}