#include "core/interface/layout.h"

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

        current = widgets.begin();
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

        current = widgets.begin();
    }

    Layout::~Layout()
    {
        //widgets.clear();
    }

    void Layout::pushFront(std::shared_ptr<Widget> widget)
    {
        widgets.push_front(widget);
        update();
    }

    void Layout::pushBack(std::shared_ptr<Widget> widget)
    {
        widgets.push_back(widget);
        update();
    }

    void Layout::popFront()
    {
        widgets.pop_front();
    }

    void Layout::popBack()
    {
        widgets.pop_back();
    }

    void Layout::clear()
    {
        widgets.clear();
    }

    void Layout::update()
    {
        unsigned scalable_count = static_cast<unsigned>(widgets.size());
        if (stacking == Stacking::Vertical)
        {
            unsigned scalable_size = geometry.height - margin.top - margin.bottom - spacing.vertical * (scalable_count - 1);
            unsigned medium_height = scalable_size / scalable_count;
            bool allocated;
            bool* processed = new bool[widgets.size()]{ };
            do
            {
                allocated = true;
                size_t j = 0;
                for (auto& widget : widgets)
                {
                    if (!processed[j])
                    {
                        if (widget->size_policy.vertical == Interface::Widget::SizePolicy::Fixed)
                        {
                            processed[j] = true;
                            scalable_count--;
                            if (scalable_count == 0)
                            {
                                break;
                            }
                            scalable_size -= widget->base_size.height;
                            medium_height = scalable_size / scalable_count;
                            allocated = false;
                        }
                        else if (widget->minimum_size.height > medium_height)
                        {
                            processed[j] = true;
                            scalable_count--;
                            if (scalable_count == 0)
                            {
                                break;
                            }
                            scalable_size -= widget->minimum_size.height;
                            medium_height = scalable_size / scalable_count;
                            allocated = false;
                        }
                    }
                    j++;
                }
            } while ((!allocated) && (scalable_count != 0));
            size_t j = 0;
            unsigned current_y = margin.top;
            for (auto& widget : widgets)
            {
                widget->setX(geometry.x + margin.left);
                widget->setY(geometry.y + current_y);
                if (!processed[j])
                {
                    widget->setHeight(medium_height);
                }
                else if (widget->size_policy.vertical == Interface::Widget::SizePolicy::Fixed)
                {
                    widget->setHeight(widget->base_size.height);
                }
                else
                {
                    widget->setHeight(widget->minimum_size.height);
                }
                if (widget->size_policy.horizontal == Interface::Widget::SizePolicy::Fixed)
                {
                    widget->setWidth(widget->base_size.width);
                }
                else
                {
                    widget->setWidth(geometry.width - margin.left - margin.right);
                }
                current_y += widget->height() + spacing.vertical;
                j++;
            }
        }
        else if (stacking == Stacking::Horizontal)
        {
            unsigned scalable_size = geometry.width - margin.left - margin.right - spacing.horizontal * (scalable_count - 1);
            unsigned medium_width = scalable_size / scalable_count;
            bool allocated;
            bool* processed = new bool[widgets.size()]{ };
            do
            {
                allocated = true;
                size_t j = 0;
                for (auto& widget : widgets)
                {
                    if (!processed[j])
                    {
                        if (widget->size_policy.horizontal == Interface::Widget::SizePolicy::Fixed)
                        {
                            processed[j] = true;
                            scalable_count--;
                            if (scalable_count == 0)
                            {
                                break;
                            }
                            scalable_size -= widget->base_size.width;
                            medium_width = scalable_size / scalable_count;
                            allocated = false;
                        }
                        else if (widget->minimum_size.width > medium_width)
                        {
                            processed[j] = true;
                            scalable_count--;
                            if (scalable_count == 0)
                            {
                                break;
                            }
                            scalable_size -= widget->minimum_size.width;
                            medium_width = scalable_size / scalable_count;
                            allocated = false;
                        }
                    }
                    j++;
                }
            } while ((!allocated) && (scalable_count != 0));
            size_t j = 0;
            unsigned current_x = margin.left;
            for (auto& widget : widgets)
            {
                widget->setX(geometry.x + current_x);
                widget->setY(geometry.y + margin.top);
                if (!processed[j])
                {
                    widget->setWidth(medium_width);
                }
                else if (widget->size_policy.horizontal == Interface::Widget::SizePolicy::Fixed)
                {
                    widget->setWidth(widget->base_size.width);
                }
                else
                {
                    widget->setWidth(widget->minimum_size.width);
                }
                if (widget->size_policy.vertical == Interface::Widget::SizePolicy::Fixed)
                {
                    widget->setHeight(widget->base_size.height);
                }
                else
                {
                    widget->setHeight(geometry.height - margin.top - margin.bottom);
                }
                current_x += widget->width() + spacing.horizontal;
                j++;
            }
        }
        current = widgets.begin();
    }

    bool Layout::onControl(Control::VirtualGamepad::KeyCode code)
    {
        //auto& widget = (*current);
        if ((*current)->onControl(code))
        {
            return true;
        }
        else
        {
            if (stacking == Stacking::Horizontal)
            {
                switch (code)
                {
                case Control::VirtualGamepad::Left:
                    if (current != widgets.begin())
                    {
                        (*current)->setInactive();
                        current--;
                        (*current)->setActive();
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                case Control::VirtualGamepad::Right:
                    if (current != widgets.end())
                    {
                        (*current)->setInactive();
                        current++;
                        (*current)->setActive();
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                default:
                    return false;
                }
            }
            else
            {
                switch (code)
                {
                case Control::VirtualGamepad::Up:
                    if (current != widgets.begin())
                    {
                        (*current)->setInactive();
                        current--;
                        (*current)->setActive();
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                case Control::VirtualGamepad::Down:
                    if (current != widgets.end())
                    {
                        (*current)->setInactive();
                        current++;
                        (*current)->setActive();
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                default:
                    return false;
                }
            }
        }
    }

    void Layout::render()
    {
        for (auto& widget : widgets)
            widget->render();
    }
}
