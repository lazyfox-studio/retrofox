#pragma once

#include "SDL.h"

namespace Control
{
    class VirtualGamepad
    {
    public:
        struct Keys
        {
            /// Left cross
            bool up;
            bool down;
            bool left;
            bool right;
            /// Right buttons bar
            bool a;
            bool b;
            bool x;
            bool y;
        };
        Keys keys;

        /**
         * @brief Process input, and update virtual gamepad status
         * @param event Event that may be an input event
        */
        void processInput(SDL_Event event);

        /**
         * @brief Reset key status
        */
        void resetState();

        static VirtualGamepad& instance();
    };
}