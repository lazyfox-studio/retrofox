#include "control/virtualgamepad.h"

namespace Control
{
    void VirtualGamepad::processInput(SDL_Event event)
    {
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_RETURN:
                keys.a = true;
                break;
            case SDLK_BACKSPACE:
                keys.b = true;
                break;
            }
        }
    }

    void VirtualGamepad::resetState()
    {
        keys = {false, false, false, false, false, false, false, false};
    }

    VirtualGamepad& VirtualGamepad::instance()
    {
        static VirtualGamepad inst;
        return inst;
    }
}