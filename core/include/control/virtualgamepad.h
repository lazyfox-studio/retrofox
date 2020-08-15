#pragma once

#include "SDL.h"

namespace Control
{
    class VirtualGamepad
    {
    public:
        enum KeyCode
        {
            empty,
            /// Left cross
            up,
            down,
            left,
            right,
            /// Right buttons bar
            a,
            b,
            x,
            y
        };

        /**
         * @brief Process input, and update virtual gamepad status
         * @param event Event that may be an input event
        */
        KeyCode processInput(SDL_Event event);

        static VirtualGamepad& instance();
    };
}
