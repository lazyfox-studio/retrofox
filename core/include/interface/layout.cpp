#include "interface/layout.h"

Interface::Layout::Layout() : Interface::Widget::Widget()
{
    margin.left   = 0;
    margin.top    = 0;
    margin.right  = 0;
    margin.bottom = 0;

    stacking = Stacking::vertical;
}

Interface::Layout::Layout(int x, int y, unsigned height, unsigned width)
    : Interface::Widget::Widget(x, y, height, width)
{
    margin.left = 0;
    margin.top = 0;
    margin.right = 0;
    margin.bottom = 0;

    stacking = Stacking::vertical;
}