#pragma once

#include <map>
#include <string>

#include <QImage>


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
         std::map<std::string, QImage*> buffer;

    public:
        /**
         * @brief Loads texture to memory if not already present
         * @param path Path to texture
         * @return QImage Pointer to texture
        */
        QImage* load(const std::string& path);

        /**
         * @brief Unloads texture from memory
         * @param path Path to texture
        */
        void unload(const std::string& path);

        /**
         * @brief Returns buffer instance
         * @return Graphics::TextureBuffer Instance
        */
        static TextureBuffer instance();
    };
}
