#include "interface/Widget.h"

namespace Interface
{
    Widget::Widget()
    {
        size_policy.vertical   = size_policy.scalable;
        size_policy.horizontal = size_policy.scalable;

        minimum_size.height = 0;
        minimum_size.width  = 0;

        maximum_size.height = UINT_MAX;
        maximum_size.width  = UINT_MAX;
    }

    Widget::Widget(int x, int y, unsigned height, unsigned width)
    {
        geometry = {x, y, height, width};

        size_policy.vertical   = size_policy.scalable;
        size_policy.horizontal = size_policy.scalable;

        minimum_size.height = 0;
        minimum_size.width  = 0;

        maximum_size.height = UINT_MAX;
        maximum_size.width  = UINT_MAX;
    }

    Widget::~Widget()
    {

    }
}
