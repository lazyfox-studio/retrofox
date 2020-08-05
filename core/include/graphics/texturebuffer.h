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
    */
    class TextureBuffer
    {
     private:
         /**
          * @brief Map as a buffer for textures
         */
         std::map<std::string, std::shared_ptr<Graphics::Texture>> buffer;

    public:
        /**
         * @brief Loads texture to memory if not already present
         * @param path Path to texture
         * @return QImage Pointer to texture
        */
        std::shared_ptr<Graphics::Texture> load(SDL_Renderer* renderer, const std::string& path);

        /**
         * @brief Unloads texture from memory
         * @param path Path to texture
        */
        void unload(const std::string& path);

        /**
         * @brief Returns buffer instance
         * @return Graphics::TextureBuffer Instance reference
        */
        static TextureBuffer& instance();
    };
}
