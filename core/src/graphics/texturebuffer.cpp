#include "graphics/texturebuffer.h"

std::map<std::string, QImage*>* buffer = new std::map<std::string, QImage*>;

QImage* Graphics::TextureBuffer::load(const std::string& path)
{
    /*std::map<std::string, QImage*>::iterator pair = buffer.find(path);
    if (pair != buffer.end())
    {
        return (*pair).second;
    }*/
    QImage* image = new QImage(path.c_str());
    //buffer.insert(std::pair<std::string, QImage*>(path, image));
    buffer->clear();
    return image;
}

void Graphics::TextureBuffer::unload(const std::string& path)
{
    //std::map<std::string, QImage*>::iterator pair = buffer.find(path);
    /*if (pair != buffer.end())
    {
        delete (*pair).second;
        buffer.erase(path);
    */
}