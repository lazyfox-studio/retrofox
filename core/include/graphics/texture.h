#pragma once

#include <string>

#include <QOpenGLFunctions>
#include <QImage>

namespace Graphics
{
    class Texture
    {
    private:
        QImage image;
        GLuint texture_name;

    public:
        Texture() = delete;
        Texture(const std::string& path);
        Texture(const Texture& texture);
        ~Texture();

        /**
         * @brief
         * @return Array of pixels
        */
        uchar* pixels();
        /**
         * @brief 
         * @return Name of texture 
        */
        GLuint  name();
        GLsizei height();
        GLsizei width();
    };
}