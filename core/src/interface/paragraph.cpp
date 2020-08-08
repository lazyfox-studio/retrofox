#include "interface/paragraph.h"

namespace Interface
{
    void Paragraph::organizeTextLines(std::shared_ptr<Graphics::Font> font, const std::string& text, unsigned max_width, bool word_wrap)
    {
        m_lines.clear();
        unsigned chars_per_line = static_cast<unsigned>(floor(max_width / font->averageCharWidth()));
        size_t index = 0, start = 0, line_length = 0, prev_space = 0;
        for (; index < text.size(); index++)
        {
            auto c = text[index];
            if (c == ' ')
            {
                prev_space = index;
                if (index == start)
                {
                    start++;
                    line_length--;
                }
            }
            line_length++;
            if (line_length >= chars_per_line)
            {
                if (word_wrap)
                {
                    if ((c != ' ') && (text[index + 1] != ' '))
                    {
                        line_length = prev_space - start;
                        index = prev_space;
                    }
                }
                std::string line = text.substr(start, line_length);
                m_lines.push_back(line);
                start = index + 1;
                line_length = 0;
            }
        }
        if (line_length > 0)
        {
            std::string last_line = text.substr(start);
            m_lines.push_back(last_line);
        }
    }

    void Paragraph::renderTextLines(SDL_Renderer* renderer, std::shared_ptr<Graphics::Font> font)
    {
        m_sprites.clear();
        m_sprites.reserve(m_lines.size());
        int top_offset = 0;
        for (const auto& line : m_lines)
        {
            m_sprites.emplace_back(renderer, font, geometry.x, geometry.y + top_offset, line);
            top_offset += m_sprites.back().height() + m_line_spacing;
        }
    }
    
    Paragraph::Paragraph(SDL_Renderer* renderer, std::shared_ptr<Graphics::Font> font, int x, int y, unsigned max_width, const std::string& text, SDL_Color color)
        : Widget(x, y), m_line_spacing(4)
    {
        organizeTextLines(font, text, max_width, true);
        renderTextLines(renderer, font);
    }

    Paragraph::~Paragraph()
    {

    }

    void Paragraph::render()
    {
        for (auto& sprite : m_sprites)
            sprite.render();
    }
}
