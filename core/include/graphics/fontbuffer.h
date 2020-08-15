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
     * @brief Font buffer
     * @details Stores fonts loaded by Graphics::Font class
     */
    class FontBuffer
    {
    private:
        /// Map as a buffer for fonts
        FontMap buffer;

    public:
        /**
         * @brief Loads font to memory if not already presented
         * @param path Path to TrueType font file
         * @param size Size of glyphs (in pixels) to load
         * @return Pointer to font
        */
        FontPtr load(const std::string& path, int size);

        /**
         * @brief Unloads font from memory
         * @param path Path to TrueType font file
         * @param size Size of glyphs (in pixels) to load
        */
        void unload(const std::string& path, int size);

        /**
         * @brief Returns buffer instance
         * @return Instance reference
        */
        static FontBuffer& instance();
    };
}
