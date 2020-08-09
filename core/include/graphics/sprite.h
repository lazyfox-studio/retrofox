#pragma once

#include <memory>

#include <SDL.h>

#include "graphics/texture.h"
#include "graphics/texturebuffer.h"

namespace Graphics
{
    /**
     * @brief Sprite controller
     * @details Class to work with graphical (texture-based) sprites
     */
    class Sprite
    {
    protected:
        /// Pointer to texture
        std::shared_ptr<Graphics::Texture> p_texture;

        /// Geometric parameters of sprite
        SDL_Rect m_geometry;

        /// Renderer
        SDL_Renderer* p_renderer;

    public:
        /// Default constructor is not provided
        Sprite() = default;

        /**
         * @brief Constructor-initializer (from path)
         * @param renderer Renderer
         * @param path Path to texture image
         */
        Sprite(SDL_Renderer* renderer, const std::string& path);

        /**
         * @brief Constructor-initializer (from path with given geometry)
         * @param renderer Renderer
         * @param path Path to texture image
         * @param x Coordinate X value
         * @param y Coordinate Y value
         * @param height Height value
         * @param width Width value
         * @todo Swap width/height parameters
         */
        Sprite(SDL_Renderer* renderer, const std::string& path, int x, int y, int height, int width);

        /**
         * @brief Constructor-initializer (from loaded texture)
         * @param renderer Renderer
         * @param texture Pointer to loaded texture
         */
        Sprite(SDL_Renderer* renderer, std::shared_ptr<Graphics::Texture> texture);

        /// Copy constructor
        Sprite(const Sprite& sprite);

        /// Move constructor
        Sprite(Sprite&&) = default;

        /// Destructor
        ~Sprite();

        /// Move-assignment operator
        Sprite& operator=(const Sprite&) = default;


        /**
         * @brief Renders sprite
         * @details Renders sprite based on m_geometry with given renderer
         */
        virtual void render();


        /**
         * @brief Getter for geometric parameters of sprite
         * @return Geometric parameters as SDL_Rect
         */
        SDL_Rect geometry() const;

        /**
         * @brief Getter for coordinate X value
         * @return Coordinate X value
         */
        int x() const;

        /**
         * @brief Getter for coordinate Y value
         * @return Coordinate Y value
         */
        int y() const;

        /**
         * @brief Getter for width value
         * @return Width value
         */
        int width() const;

        /**
         * @brief Getter for height value
         * @return Height value
         */
        int height() const;

        /**
         * @brief Getter for renderer
         * @return Pointer to renderer
         */
        SDL_Renderer* renderer() const;


        /**
         * @brief Setter for coordinate X value
         * @param x New coordinate X value
         */
        void setX(int x);

        /**
         * @brief Setter for coordinate Y value
         * @param y New coordinate Y value
         */
        void setY(int y);

        /**
         * @brief Setter for height value
         * @param height New height value
         */
        void setHeight(int height);

        /**
         * @brief Setter for width value
         * @param width New width value
         */
        void setWidth(int width);
    };
}
