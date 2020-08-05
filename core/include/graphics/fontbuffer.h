#pragma once

#include <map>
#include <memory>
#include <string>

#include <SDL.h>

#include "graphics/font.h"


namespace Graphics
{
    /**
     * @brief Texture buffer
    */
    class FontBuffer
    {
    private:
        typedef std::pair<std::string, int> TFontKey;
        typedef std::map <TFontKey, std::shared_ptr<Graphics::Font>> TFontMap;
        /**
         * @brief Map as a buffer for textures
        */
        TFontMap buffer;

    public:
        /**
         * @brief Loads texture to memory if not already present
         * @param path Path to texture
         * @return QImage Pointer to texture
        */
        std::shared_ptr<Graphics::Font> load(const std::string& path, int size);

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
