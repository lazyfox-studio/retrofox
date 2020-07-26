#include "graphics/texture.h"

Graphics::Texture::Texture(const std::string& path)
{
    image.load(path.c_str());
    glGenTextures(1, &texture_name);
}

Graphics::Texture::Texture(const Texture& texture)
{
    image = texture.image;
    texture_name = texture.texture_name;
}

Graphics::Texture::~Texture()
{

}

uchar* Graphics::Texture::pixels()
{
    return image.bits();
}

GLuint Graphics::Texture::name()
{
    return texture_name;
}

GLsizei Graphics::Texture::height()
{
    return image.height();
}

GLsizei Graphics::Texture::width()
{
    return image.width();
}