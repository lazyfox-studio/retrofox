#include "interface/Widget.h"

namespace Interface
{
    Widget::Widget()
    {
        size_policy.vertical   = SizePolicy::Scalable;
        size_policy.horizontal = SizePolicy::Scalable;

        minimum_size.height = 0;
        minimum_size.width  = 0;

        maximum_size.height = UINT_MAX;
        maximum_size.width  = UINT_MAX;
        
        base_size.height = 0;
        base_size.width  = 0;
    }

    Widget::Widget(int x, int y, unsigned height, unsigned width)
    {
        geometry = {x, y, height, width};

        size_policy.vertical   = SizePolicy::Scalable;
        size_policy.horizontal = SizePolicy::Scalable;

        minimum_size.height = 0;
        minimum_size.width  = 0;

        maximum_size.height = UINT_MAX;
        maximum_size.width  = UINT_MAX;

        base_size.height = height;
        base_size.width  = width;
    }

    Widget::~Widget()
    {

    }

    Graphics::Sprite* Widget::sprite()
    {
        throw "Filler";
    }
}
