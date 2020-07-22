#pragma once

#include <map>
#include <string>

#include <QImage>

namespace Graphics
{
    static class TextureBuffer
    {
     private:
         /**
          * @brief 
         */
         static std::map<std::string, QImage*> buffer;

    public:
        /**
         * @brief Loads texture to memory if not already present
         * @param path Path to texture
         * @return Pointer to texture
        */
        static QImage* load(const std::string& path);
        /**
         * @brief Unloads texture from memory
         * @param path Path to texture
        */
        static void unload(const std::string& path);
    };
}