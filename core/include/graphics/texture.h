#pragma once

#include <string>

#include <SDL.h>

namespace Graphics
{
    /**
     * @brief Texture image
     * @details Stores information about SDL_Texture object
     */
    class Texture
    {
    protected:
        /// Pointer to texture service data
        SDL_Texture* sdl_texture;

        /// Represents texture size
        struct Size
        {
            int height; ///< Texture height
            int width;  ///< Texture width
        };
        Size size; ///< Texture size

    public:
        /// Default constructor is not provided
        Texture() = delete;

        /**
         * @brief Constructor-ininitalizer (from surface)
         * @param renderer Renderer
         * @param surface Pointer to pre-rendered surface
         */
        Texture(SDL_Renderer* renderer, SDL_Surface* surface);

        /**
         * @brief Constructor-ininitalizer (from path)
         * @param renderer Renderer
         * @param path Path to image file
         */
        Texture(SDL_Renderer* renderer, const std::string& path);

        /// Copy constructior is not provided
        Texture(const Texture& texture) = delete;

        /// Destructor
        ~Texture();


        /**
         * @brief Getter for texture service data
         * @return Pointer to texture
         */
        SDL_Texture* texture();

        /**
         * @brief Getter for height value
         * @return Height of texture image
         */
        int height();
        
        /**
         * @brief Getter for width value
         * @return Width of texture image
         */
        int width();
    };
}
