#pragma once

#include "SDL.h"

namespace Control
{
    class VirtualGamepad
    {
    public:
        enum KeyCode
        {
            Empty,
            /// Left cross
            Up,
            Down,
            Left,
            Right,
            /// Right buttons bar
            A,
            B,
            X,
            Y
        };

        /**
         * @brief Process input, and update virtual gamepad status
         * @param event Event that may be an input event
        */
        KeyCode processInput(SDL_Event event);

        static VirtualGamepad& instance();
    };
}
