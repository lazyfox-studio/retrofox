#pragma once

#include <memory>

#include <SDL.h>

#include "graphics/texture.h"
#include "graphics/texturebuffer.h"

namespace Graphics
{
    /**
     * @brief Sprite
    */
    class Sprite
    {
    protected:
        std::shared_ptr<Graphics::Texture> p_texture;
        SDL_Rect m_geometry;

        SDL_Renderer* p_renderer;

    public:
        Sprite() = default;
        Sprite(SDL_Renderer* renderer, const std::string& path);
        Sprite(SDL_Renderer* renderer, const std::string& path, int x, int y, int height, int width);
        Sprite(SDL_Renderer* renderer, Graphics::Texture* texture);
        Sprite(const Sprite& sprite);
        Sprite(Sprite&&) = default;
        ~Sprite();
        Sprite& operator=(const Sprite&) = default;

        void render();

        SDL_Rect geometry() const;
        int x() const;
        int y() const;
        int height() const;
        int width() const;
        SDL_Renderer* renderer() const;

        void setX(int x);
        void setY(int y);
        void setHeight(int height);
        void setWidth(int width);
    };
}