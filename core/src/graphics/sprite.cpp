#include "graphics/sprite.h"

Graphics::Sprite::Sprite(const std::string& path)
{
    image = Graphics::TextureBuffer::instance().load(path);
    geometry = {0, 0, (unsigned) image->height(), (unsigned) image->width()};
}

Graphics::Sprite::Sprite(const std::string& path, int x, int y, unsigned height, unsigned width)
{
    image = Graphics::TextureBuffer::instance().load(path);
    geometry = {x, y, height, width};
}

Graphics::Sprite::Sprite(const Sprite& sprite)
{
    image = sprite.image;
    geometry = sprite.geometry;
}

Graphics::Sprite::~Sprite()
{
    
}

int Graphics::Sprite::x() const
{
    return geometry.x;
}

int Graphics::Sprite::y() const
{
    return geometry.y;
}

unsigned Graphics::Sprite::height() const
{
    return geometry.height;
}

unsigned Graphics::Sprite::width() const
{
    return geometry.width;
}

QImage* Graphics::Sprite::texture() const
{
    return image;
}

void Graphics::Sprite::setX(unsigned x)
{
    geometry.x = x;
}

void Graphics::Sprite::setY(unsigned y)
{
    geometry.y = y;
}

void Graphics::Sprite::setHeight(unsigned height)
{
    geometry.height = height;
}

void Graphics::Sprite::setWidth(unsigned width)
{
    geometry.width = width;
}