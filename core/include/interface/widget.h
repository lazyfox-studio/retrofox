#pragma once

#include <limits>

namespace Interface
{
    /**
     * @brief UI element
    */
    class Widget
    {
    private:
        

    public:
        struct UIGeometry
        {
            int x;
            int y;
            unsigned height;
            unsigned width;
        };
        UIGeometry geometry;

        struct SizePolicy
        {
            enum Policy
            {
                fixed,
                scalable
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

        Widget();
        Widget(int x, int y, unsigned height, unsigned width);
        ~Widget();
    };
}