#include "control/virtualgamepad.h"

namespace Control
{
    VirtualGamepad::KeyCode VirtualGamepad::processInput(SDL_Event event)
    {
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                return KeyCode::Up;
            case SDLK_LEFT:
                return KeyCode::Left;
            case SDLK_RIGHT:
                return KeyCode::Right;
            case SDLK_DOWN:
                return KeyCode::Down;
            case SDLK_RETURN:
                return KeyCode::A;
            case SDLK_BACKSPACE:
                return KeyCode::B;
            case SDLK_LCTRL:
                return KeyCode::X;
            case SDLK_LSHIFT:
                return KeyCode::Y;
            default:
                return KeyCode::Empty;
            }
        }
        return KeyCode::Empty;
    }

    VirtualGamepad& VirtualGamepad::instance()
    {
        static VirtualGamepad inst;
        return inst;
    }
}
