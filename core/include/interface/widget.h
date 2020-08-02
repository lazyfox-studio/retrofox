#pragma once

#include <limits>

#include "graphics/sprite.h"

#include "renderer.h"

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
        Widget(int x, int y, unsigned height, unsigned width);
        ~Widget();

        int x();
        int y();
        unsigned height();
        unsigned width();

        virtual void setX(int x);
        virtual void setY(int y);
        virtual void setHeight(unsigned height);
        virtual void setWidth(unsigned width);

        virtual void render() = 0;
    };
}