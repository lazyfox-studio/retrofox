#include "interface/layout.h"

Interface::Layout::Layout() : Interface::Widget::Widget()
{
    margin.left   = 0;
    margin.top    = 0;
    margin.right  = 0;
    margin.bottom = 0;

    spacing.vertical   = 0;
    spacing.horizontal = 0;

    stacking = Stacking::Vertical;
}

Interface::Layout::Layout(int x, int y, unsigned height, unsigned width)
    : Interface::Widget::Widget(x, y, height, width)
{
    margin.left = 0;
    margin.top = 0;
    margin.right = 0;
    margin.bottom = 0;

    spacing.vertical = 0;
    spacing.horizontal = 0;

    stacking = Stacking::Vertical;
}

void Interface::Layout::pushForward(Widget& widget)
{
    widgets.push_front(widget);
    update();
}

void Interface::Layout::pushBackward(Widget& widget)
{
    widgets.push_back(widget);
    update();
}

void Interface::Layout::update()
{
    if (stacking == Stacking::Vertical)
    {
        unsigned fixed_size    = 0;
        unsigned scalable_size = 0;
        size_t scalable_count = 0;
        size_t count = widgets.size();
        for (std::list<Interface::Widget>::iterator i = widgets.begin(); i != widgets.end(); ++i)
        {
            if ((*i).size_policy.vertical == Interface::Widget::SizePolicy::Fixed)
            {
                fixed_size = (*i).base_size.height;
            }
            else
            {
                scalable_count++;
            }
        }

        //TODO: Refactor this all for minimum size support!!!
        scalable_size = geometry.height - margin.top - margin.bottom - (count - 1) * spacing.vertical;
        unsigned temp_size = margin.top;

        for (std::list<Interface::Widget>::iterator i = widgets.begin(); i != widgets.end(); ++i)
        {
            if ((*i).size_policy.vertical == Interface::Widget::SizePolicy::Fixed)
            {
                (*i).geometry.x = geometry.x + margin.left;
                (*i).geometry.y = geometry.y + temp_size;

                (*i).geometry.height = (*i).base_size.height;
                if ((*i).size_policy.horizontal == Interface::Widget::SizePolicy::Fixed)
                {
                    (*i).geometry.width = (*i).base_size.width;
                }
                else
                {
                    (*i).geometry.width = geometry.width - margin.left - margin.right;
                }
            }
            else
            {
                (*i).geometry.x = geometry.x + margin.left;
                (*i).geometry.y = geometry.y + temp_size;

                (*i).geometry.height = scalable_size / scalable_count;
                if ((*i).size_policy.horizontal == Interface::Widget::SizePolicy::Fixed)
                {
                    (*i).geometry.width = (*i).base_size.width;
                }
                else
                {
                    (*i).geometry.width = geometry.width - margin.left - margin.right;
                }
            }

            temp_size += (*i).geometry.height + spacing.vertical;
        }
    }
}
    stacking = Stacking::Vertical;
}

void Interface::Layout::render(Renderer& renderer)
{
    for (Interface::Widget* widget : widgets)
        widget->render(renderer);
}
