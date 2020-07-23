#include "graphics/texturebuffer.h"

QImage* Graphics::TextureBuffer::load(const std::string& path)
{
    std::map<std::string, QImage*>::iterator pair = buffer.find(path);
    if (pair != buffer.end())
    {
        return (*pair).second;
    }
    QImage* image = new QImage(path.c_str());
    buffer.insert(std::pair<std::string, QImage*>(path, image));
    return image;
}

void Graphics::TextureBuffer::unload(const std::string& path)
{
    std::map<std::string, QImage*>::iterator pair = buffer.find(path);
    if (pair != buffer.end())
    {
        delete (*pair).second;
        buffer.erase(path);
    }
}

Graphics::TextureBuffer Graphics::TextureBuffer::instance()
{
    TextureBuffer inst;
    return inst;
}
