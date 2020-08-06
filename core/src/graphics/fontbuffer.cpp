#include "graphics/fontbuffer.h"

namespace Graphics
{
    std::shared_ptr<Graphics::Font> FontBuffer::load(const std::string& path, int size)
    {
        FontMap::iterator pair = buffer.find(FontKey(path, size));
        if (pair != buffer.end())
        {
            return (*pair).second;
        }
        auto font = std::make_shared<Graphics::Font>(path.c_str(), size);
        buffer.insert(std::pair<FontKey, std::shared_ptr<Graphics::Font>>(FontKey(path, size), font));
        return font;
    }
}

void Graphics::FontBuffer::unload(const std::string& path, int size)
{
    std::map<FontKey, std::shared_ptr<Graphics::Font>>::iterator pair = buffer.find(FontKey(path, size));
    if (pair != buffer.end())
    {
        if ((*pair).second.unique())
        {
            (*pair).second.reset();
            buffer.erase(FontKey(path, size));
        }
        else
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Attempt to unload sprite %s that is still used", path.c_str());
        }
    }
}

Graphics::FontBuffer& Graphics::FontBuffer::instance()
{
    static FontBuffer inst;
    return inst;
}
