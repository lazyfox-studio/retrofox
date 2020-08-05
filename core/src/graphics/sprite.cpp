#include "graphics/sprite.h"

namespace Graphics
{
    Sprite::Sprite(SDL_Renderer* renderer, const std::string& path)
    {
        p_renderer = renderer;
        p_texture = Graphics::TextureBuffer::instance().load(p_renderer, path);
        m_geometry = { 0, 0, p_texture->width(), p_texture->height() };
    }

    Sprite::Sprite(SDL_Renderer* renderer, const std::string& path, int x, int y, int height, int width)
    {
        p_texture = Graphics::TextureBuffer::instance().load(renderer, path);
        m_geometry = { x, y, width, height };
    }

    Sprite::Sprite(SDL_Renderer* renderer, std::shared_ptr<Graphics::Texture> texture)
        : p_renderer(renderer), p_texture(texture)
    {
        m_geometry = { 0, 0, p_texture->width(),  p_texture->height() };
    }

    Sprite::Sprite(const Sprite& sprite)
    {
        p_texture = sprite.p_texture;
        m_geometry = sprite.m_geometry;
    }

    Sprite::~Sprite()
    {

    }

    void Sprite::render()
    {
        SDL_RenderCopy(p_renderer, p_texture->texture(), NULL, &m_geometry);
    }

    SDL_Rect Sprite::geometry() const
    {
        return m_geometry;
    }

    int Sprite::x() const
    {
        return m_geometry.x;
    }

    int Sprite::y() const
    {
        return m_geometry.y;
    }

    int Sprite::height() const
    {
        return m_geometry.h;
    }

    int Sprite::width() const
    {
        return m_geometry.w;
    }

    SDL_Renderer* Sprite::renderer() const
    {
        return p_renderer;
    }

    void Sprite::setX(int x)
    {
        m_geometry.x = x;
    }

    void Sprite::setY(int y)
    {
        m_geometry.y = y;
    }

    void Sprite::setHeight(int height)
    {
        m_geometry.h = height;
    }

    void Sprite::setWidth(int width)
    {
        m_geometry.w = width;
    }
}