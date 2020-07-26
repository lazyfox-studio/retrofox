#pragma once

#include <QImage>

#include "graphics/texture.h"
#include "graphics/texturebuffer.h"

namespace Graphics
{
    /**
     * @brief Sprite
    */
    class Sprite
    {
    private:
        Graphics::Texture* p_texture;

        struct Geometry
        {
            int x;
            int y;
            unsigned height;
            unsigned width;
        };
        Geometry geometry;

    public:
        Sprite() = delete;
        Sprite(const std::string& path);
        Sprite(const std::string& path, int x, int y, unsigned height, unsigned width);
        Sprite(const Sprite& sprite);
        ~Sprite();


        int x() const;
        int y() const;
        unsigned height() const;
        unsigned width() const;
        Graphics::Texture* texture() const;

        void setX(unsigned x);
        void setY(unsigned y);
        void setHeight(unsigned height);
        void setWidth(unsigned width);
    };
}