#include "core/graphics/fontbuffer.h"

namespace Graphics
{
    FontPtr FontBuffer::load(const std::string& path, int size)
    {
        auto ipair = buffer.find(FontKey(path, size));
        if (ipair != buffer.end())
        {
            return (*ipair).second;
        }
        auto font = std::make_shared<Graphics::Font>(path.c_str(), size);
        buffer.insert(std::pair<FontKey, FontPtr>(FontKey(path, size), font));
        return font;
    }

    void FontBuffer::unload(const std::string& path, int size)
    {
        auto ipair = buffer.find(FontKey(path, size));
        if (ipair != buffer.end())
        {
            if ((*ipair).second.unique())
            {
                (*ipair).second.reset();
                buffer.erase(FontKey(path, size));
            }
            else
            {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Attempt to unload sprite %s that is still used", path.c_str());
            }
        }
    }

    FontBuffer& Graphics::FontBuffer::instance()
    {
        static FontBuffer inst;
        return inst;
    }
}
