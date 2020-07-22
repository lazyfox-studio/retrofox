#pragma once

#include <QImage>

#include "graphics/texturebuffer.h"

namespace Graphics
{
    /**
     * @brief Sprite
    */
    class Sprite
    {
    private:
        QImage* image;

        struct Geometry
        {
            int x;
            int y;
            unsigned height;
            unsigned width;
        };
        Geometry geometry;

        Sprite();
    public:
        Sprite(const std::string& path);
        Sprite(const std::string& path, int x, int y, unsigned height, unsigned width);
        Sprite(const Sprite& sprite);
        ~Sprite();


        int x();
        int y();
        unsigned height();
        unsigned width();

        void setX(unsigned x);
        void setY(unsigned y);
        void setHeight(unsigned height);
        void setWidth(unsigned width);
    };
}