#pragma once

#include <map>
#include <memory>
#include <string>

#include <SDL.h>

#include "graphics/texture.h"


namespace Graphics
{
    /**
     * @brief Texture buffer 
     * @details Stores textures loaded by Graphics::Texture class
     */
    class TextureBuffer
    {
     private:
         /// Map as a buffer for textures
         std::map<std::string, std::shared_ptr<Graphics::Texture>> buffer;

    public:
        /**
         * @brief Loads texture to memory if not already presented
         * @param renderer Renderer
         * @param path Path to texture image file
         * @return Pointer to texture
        */
        std::shared_ptr<Graphics::Texture> load(SDL_Renderer* renderer, const std::string& path);

        /**
         * @brief Unloads texture from memory
         * @param path Path to texture image file
        */
        void unload(const std::string& path);

        /**
         * @brief Returns buffer instance
         * @return Graphics::TextureBuffer Instance reference
        */
        static TextureBuffer& instance();
    };
}
