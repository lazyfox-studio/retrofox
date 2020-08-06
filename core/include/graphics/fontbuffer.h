#pragma once

#include <map>
#include <memory>
#include <string>

#include <SDL.h>

#include "graphics/font.h"


namespace Graphics
{
    using FontKey = std::pair<std::string, int>;
    using FontPtr = std::shared_ptr<Font>;
    using FontMap = std::map <FontKey, FontPtr>;

    /**
     * @brief Texture buffer
    */
    class FontBuffer
    {
    private:
        /**
         * @brief Map as a buffer for textures
        */
        FontMap buffer;

    public:
        /**
         * @brief Loads texture to memory if not already present
         * @param path Path to texture
         * @return QImage Pointer to texture
        */
        FontPtr load(const std::string& path, int size);

        /**
         * @brief Unloads texture from memory
         * @param path Path to texture
        */
        void unload(const std::string& path, int size);

        /**
         * @brief Returns buffer instance
         * @return Graphics::TextureBuffer Instance reference
        */
        static FontBuffer& instance();
    };
}
