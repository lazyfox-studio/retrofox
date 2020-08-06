#pragma once

#include <string>

#include <SDL.h>

namespace Graphics
{
    class Texture
    {
    protected:
        SDL_Texture* sdl_texture;

        struct Size
        {
            int height;
            int width;
        };
        Size size;

    public:
        Texture() = delete;
        Texture(SDL_Renderer* renderer, SDL_Surface* surface);
        Texture(SDL_Renderer* renderer, const std::string& path);
        Texture(const Texture& texture) = delete;
        ~Texture();

        SDL_Texture* texture();
        int height();
        int width();
    };
}
