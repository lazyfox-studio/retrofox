#pragma once

#include <limits>

#include "graphics/sprite.h"

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
        Size base_size;

        Widget();
        Widget(int x, int y, unsigned height, unsigned width);
        ~Widget();

        /**
         * @brief Returns sprite pointer to draw (for Renderer::draw() method)
         * @return Pointer ro sprite
         */
        virtual Graphics::Sprite* getSprite() = 0;
    };
}