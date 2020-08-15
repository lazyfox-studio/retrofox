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
                return KeyCode::up;
            case SDLK_LEFT:
                return KeyCode::left;
            case SDLK_RIGHT:
                return KeyCode::right;
            case SDLK_DOWN:
                return KeyCode::down;
            case SDLK_RETURN:
                return KeyCode::a;
            case SDLK_BACKSPACE:
                return KeyCode::b;
            case SDLK_LCTRL:
                return KeyCode::x;
            case SDLK_LSHIFT:
                return KeyCode::y;
            default:
                return KeyCode::empty;
            }
        }
        return KeyCode::empty;
    }

    VirtualGamepad& VirtualGamepad::instance()
    {
        static VirtualGamepad inst;
        return inst;
    }
}
