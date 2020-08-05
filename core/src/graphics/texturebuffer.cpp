#include "graphics/texturebuffer.h"

namespace Graphics
{
    std::shared_ptr<Graphics::Texture> TextureBuffer::load(SDL_Renderer* renderer, const std::string& path)
    {
        std::map<std::string, std::shared_ptr<Graphics::Texture>>::iterator pair = buffer.find(path);
        if (pair != buffer.end())
        {
            return (*pair).second;
        }
        auto texture = std::make_shared<Graphics::Texture>(renderer, path.c_str());
        buffer.insert(std::pair<std::string, std::shared_ptr<Graphics::Texture>>(path, texture));
        return texture;
    }
}

void Graphics::TextureBuffer::unload(const std::string& path)
{
    std::map<std::string, std::shared_ptr<Graphics::Texture>>::iterator pair = buffer.find(path);
    if (pair != buffer.end())
    {
        if ((*pair).second.unique())
        {
            (*pair).second.reset();
            buffer.erase(path);
        }
        else
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Atemt to unload sprite %s that is still used", path.c_str());
        }  
    }
}

Graphics::TextureBuffer& Graphics::TextureBuffer::instance()
{
    static TextureBuffer inst;
    return inst;
}
