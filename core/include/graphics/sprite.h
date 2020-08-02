#pragma once

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
        Graphics::Texture* p_texture;
        SDL_Rect m_geometry;

        SDL_Renderer* p_renderer;

    public:
        Sprite() = delete;
        Sprite(SDL_Renderer* renderer, const std::string& path);
        Sprite(SDL_Renderer* renderer, const std::string& path, int x, int y, int height, int width);
        Sprite(const Sprite& sprite);
        Sprite(Sprite&&) = default;
        ~Sprite();

        void render();

        SDL_Rect geometry() const;
        int x() const;
        int y() const;
        int height() const;
        int width() const;

        void setX(int x);
        void setY(int y);
        void setHeight(int height);
        void setWidth(int width);
    };
}