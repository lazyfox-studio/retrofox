#pragma once

#include "graphics/fontbuffer.h"

namespace Graphics
{
    std::shared_ptr<Graphics::Font> FontBuffer::load(const std::string& path, int size)
    {
        TFontMap::iterator pair = buffer.find(TFontKey(path, size));
        if (pair != buffer.end())
        {
            return (*pair).second;
        }
        auto font = std::make_shared<Graphics::Font>(path.c_str(), size);
        buffer.insert(std::pair<TFontKey, std::shared_ptr<Graphics::Font>>(TFontKey(path, size), font));
        return font;
    }
}

void Graphics::FontBuffer::unload(const std::string& path, int size)
{
    std::map<TFontKey, std::shared_ptr<Graphics::Font>>::iterator pair = buffer.find(TFontKey(path, size));
    if (pair != buffer.end())
    {
        if ((*pair).second.unique())
        {
            (*pair).second.reset();
            buffer.erase(TFontKey(path, size));
        }
        else
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Atemt to unload sprite %s that is still used", path.c_str());
        }
    }
}

Graphics::FontBuffer& Graphics::FontBuffer::instance()
{
    static FontBuffer inst;
    return inst;
}
