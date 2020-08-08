#include "interface/layout.h"

namespace Interface
{
    Layout::Layout() : Interface::Widget::Widget()
    {
        margin.left = 0;
        margin.top = 0;
        margin.right = 0;
        margin.bottom = 0;

        spacing.vertical = 0;
        spacing.horizontal = 0;

        stacking = Stacking::Vertical;
    }

    Layout::Layout(int x, int y, unsigned height, unsigned width)
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

    Layout::~Layout()
    {
        widgets.clear();
    }

    void Layout::pushFront(Widget& widget)
    {
        widgets.push_front(widget);
        update();
    }

    void Layout::pushBack(Widget& widget)
    {
        widgets.push_back(widget);
        update();
    }

    void Layout::update()
    {
        size_t scalable_count = widgets.size();
        unsigned scalable_size = geometry.height - margin.top - margin.bottom - spacing.vertical * (scalable_count - 1);
        unsigned medium_height = scalable_size / scalable_count;
        if (stacking == Stacking::Vertical)
        {
            bool allocated;
            bool* processed = new bool[widgets.size()]{ };
            do
            {
                allocated = true;
                size_t j = 0;
                for (auto i = widgets.begin(); i != widgets.end(); ++i)
                {
                    Interface::Widget& widget = (*i).get();
                    if (!processed[j])
                    {
                        if (widget.size_policy.vertical == Interface::Widget::SizePolicy::Fixed)
                        {
                            processed[j] = true;
                            scalable_count--;
                            if (scalable_count == 0)
                            {
                                break;
                            }
                            scalable_size -= widget.base_size.height;
                            medium_height = scalable_size / scalable_count;
                            allocated = false;
                        }
                        else if (widget.minimum_size.height > medium_height)
                        {
                            processed[j] = true;
                            scalable_count--;
                            if (scalable_count == 0)
                            {
                                break;
                            }
                            scalable_size -= widget.minimum_size.height;
                            medium_height = scalable_size / scalable_count;
                            allocated = false;
                        }
                    }
                    j++;
                }
            } while ((!allocated) && (scalable_count != 0));
            size_t j = 0;
            unsigned current_y = margin.top;
            for (auto i = widgets.begin(); i != widgets.end(); ++i)
            {
                Interface::Widget& widget = (*i).get();
                widget.setX(geometry.x + margin.left);
                widget.setY(geometry.y + current_y);
                if (!processed[j])
                {
                    widget.setHeight(medium_height);
                }
                else if (widget.size_policy.vertical == Interface::Widget::SizePolicy::Fixed)
                {
                    widget.setHeight(widget.base_size.height);
                }
                else
                {
                    widget.setHeight(widget.minimum_size.height);
                }
                if (widget.size_policy.horizontal == Interface::Widget::SizePolicy::Fixed)
                {
                    widget.setWidth(widget.base_size.width);
                }
                else
                {
                    widget.setWidth(geometry.width - margin.left - margin.right);
                }
                current_y += widget.height() + spacing.vertical;
                j++;
            }
        }
        else if (stacking == Stacking::Horizontal)
        {

        }
    }

    void Layout::render()
    {
        for (auto& widget_reference : widgets)
            widget_reference.get().render();
    }
}