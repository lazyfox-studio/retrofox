#pragma once

#include <limits>

#include "control/virtualgamepad.h"
#include "graphics/sprite.h"

namespace Interface
{
    /**
     * @brief UI element
    */
    class Widget
    {
    public:
        struct UIGeometry
        {
            int x;
            int y;
            unsigned height;
            unsigned width;
        };

        struct SizePolicy
        {
            enum Policy
            {
                Fixed,
                Scalable
            };
            Policy vertical;
            Policy horizontal;
        };
        SizePolicy size_policy;

        struct Size
        {
            unsigned height;
            unsigned width;
        };
        Size minimum_size;
        Size maximum_size;
        Size base_size;

    protected:
        UIGeometry geometry;

    public:

        Widget();
        Widget(int x, int y);
        Widget(int x, int y, unsigned height, unsigned width);
        ~Widget();

        virtual void setActive();
        virtual void setInactive();

        int x();
        int y();
        unsigned height();
        unsigned width();

        virtual void setX(int x);
        virtual void setY(int y);
        virtual void setHeight(unsigned height);
        virtual void setWidth(unsigned width);

        virtual bool onControl(Control::VirtualGamepad::KeyCode code);
        virtual void render() = 0;
    };
}