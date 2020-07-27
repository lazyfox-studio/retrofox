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

void Interface::Layout::prepend(Widget& widget)
{
    widgets.push_front(widget);
    update();
}

void Interface::Layout::append(Widget& widget)
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
        for (auto& widget_reference : widgets)
        {
            Interface::Widget& widget = widget_reference.get();
            if (widget.size_policy.vertical == Interface::Widget::SizePolicy::Fixed)
            {
                fixed_size = widget.base_size.height;
            }
            else
            {
                scalable_count++;
            }
        }

        //TODO: Refactor this all for minimum size support!!!
        scalable_size = geometry.height - margin.top - margin.bottom - (count - 1) * spacing.vertical;
        unsigned temp_size = margin.top;

        for (auto& widget_reference : widgets)
        {
            Interface::Widget& widget = widget_reference.get();
            if (widget.size_policy.vertical == Interface::Widget::SizePolicy::Fixed)
            {
                widget.geometry.x = geometry.x + margin.left;
                widget.geometry.y = geometry.y + temp_size;

                widget.geometry.height = widget.base_size.height;
                if (widget.size_policy.horizontal == Interface::Widget::SizePolicy::Fixed)
                {
                    widget.geometry.width = widget.base_size.width;
                }
                else
                {
                    widget.geometry.width = geometry.width - margin.left - margin.right;
                }
            }
            else
            {
                widget.geometry.x = geometry.x + margin.left;
                widget.geometry.y = geometry.y + temp_size;

                widget.geometry.height = scalable_size / scalable_count;
                if (widget.size_policy.horizontal == Interface::Widget::SizePolicy::Fixed)
                {
                    widget.geometry.width = widget.base_size.width;
                }
                else
                {
                    widget.geometry.width = geometry.width - margin.left - margin.right;
                }
            }

            temp_size += widget.geometry.height + spacing.vertical;
        }
    }
    stacking = Stacking::Vertical;
}

void Interface::Layout::render(Renderer& renderer)
{
    for (auto& widget_reference : widgets)
        widget_reference.get().render(renderer);
}
