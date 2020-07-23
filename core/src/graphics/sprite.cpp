#include "graphics/sprite.h"

Graphics::Sprite::Sprite(const std::string& path)
{
    image = Graphics::TextureBuffer::load(path);
    geometry = {0, 0, (unsigned) image->height(), (unsigned) image->width()};
}

Graphics::Sprite::Sprite(const std::string& path, int x, int y, unsigned height, unsigned width)
{
    image = Graphics::TextureBuffer::load(path);
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

int Graphics::Sprite::x()
{
    return geometry.x;
}

int Graphics::Sprite::y()
{
    return geometry.y;
}

unsigned Graphics::Sprite::height()
{
    return geometry.height;
}

unsigned Graphics::Sprite::width()
{
    return geometry.width;
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