#pragma once

#include "SDL.h"

namespace Control
{
    /**
     * @brief Virtual gamepad controller
     * @details Class for processing events from gamepad controls
     */
    class VirtualGamepad
    {
    public:
        /// Available buttons to control
        enum KeyCode
        {
            Empty, ///< Empty (unknown button pressed)
            Up,    ///< Up (left cross)
            Down,  ///< Down (left cross)
            Left,  ///< Left (left cross)
            Right, ///< Right (left cross)
            A,     ///< A button (right bar)
            B,     ///< B button (right bar)
            X,     ///< X button (right bar)
            Y      ///< Y button (right bar)
        };

        /**
         * @brief Processes input and updates virtual gamepad status
         * @param event Event to process (may be an input event)
         * @return Button key code
         */
        KeyCode processInput(SDL_Event event);

        /**
         * @brief Returns virtual gamepad controller instance
         * @return Instance reference
         */
        static VirtualGamepad& instance();
    };
}
