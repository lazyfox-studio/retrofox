#include "interface/paragraph.h"

namespace Interface
{
    void Paragraph::organizeTextLines(std::shared_ptr<Graphics::Font> font, const std::string& text, unsigned max_width, bool word_wrap)
    {
        m_lines.clear();
        unsigned avg_char_width = font->calculateTextWidth("jiwmhx o e") / 10;
        unsigned chars_per_line = max_width / avg_char_width;
        size_t index = 0, start = 0, line_length = 0, prev_space = 0;
        for (auto c : text)
        {
            if (c == ' ')
                prev_space = index;

            line_length++;

            if (line_length >= chars_per_line)
            {
                std::string line = text.substr(start, line_length);
                m_lines.push_back(line);
                start = index + 1;
                line_length = 0;
            }

            index++;
        }
    }

    void Paragraph::renderTextLines(SDL_Renderer* renderer, std::shared_ptr<Graphics::Font> font)
    {
        m_sprites.clear();
        m_sprites.reserve(m_lines.size());
        for (const auto& line : m_lines)
            m_sprites.emplace_back(renderer, font, line);
    }
    
    Paragraph::Paragraph(SDL_Renderer* renderer, std::shared_ptr<Graphics::Font> font, int x, int y, unsigned max_width, const std::string& text, SDL_Color color)
    {
        organizeTextLines(font, text, max_width);
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
