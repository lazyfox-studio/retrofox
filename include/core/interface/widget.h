#pragma once

#include <limits>
#include <stdexcept>

#include "core/control/virtualgamepad.h"
#include "core/graphics/sprite.h"

namespace Interface
{
    /**
     * @brief UI element
     * @details Class to represent abstract UI element as widget
     */
    class Widget
    {
    public:
        /// Represents widget geometric parameters
        struct UIGeometry
        {
            int x; ///< Coordinate X value
            int y; ///< Coordinate Y value
            unsigned height; ///< Height value
            unsigned width;  ///< Width value
        };


        /// Represents widget size policy
        struct SizePolicy
        {
            /// Available size policies
            enum Policy
            {
                Fixed,   ///< Fixed size
                Scalable ///< Scalable size
            };
            Policy vertical;   ///< Vertical policy
            Policy horizontal; ///< Horizontal policy
        };

        /// Widget size policy
        SizePolicy size_policy;


        /// Represents widget size
        struct Size
        {
            unsigned height; ///< Height 
            unsigned width;  ///< Width
        };

        /// Minimum size
        Size minimum_size;

        /// Maximum size
        Size maximum_size;

        /// Base size
        Size base_size;

    protected:
        /// Geometric parameters of widget
        UIGeometry geometry;

    public:
        /// Default constructor
        Widget();

        /**
         * @brief Constructor-initializer (without size)
         * @param x Widget X coordinate
         * @param y Widget Y coordinate
         */
        Widget(int x, int y);

        /**
         * @brief Constructor-initializer
         * @param x Widget X coordinate
         * @param y Widget Y coordinate
         * @param height Widget height
         * @param width Widget width
         */
        Widget(int x, int y, unsigned height, unsigned width);

        /// Destructor
        ~Widget();


        /// Makes widget active
        virtual void setActive();

        /// Makes widget inactive (ignore control events)
        virtual void setInactive();


        /**
         * @brief Getter for coordinate X value
         * @return Coordinate X value
         */
        int x() const;

        /**
         * @brief Getter for coordinate Y value
         * @return Coordinate Y value
         */
        int y() const;

        /**
         * @brief Getter for width value
         * @return Width value
         */
        unsigned width() const;

        /**
         * @brief Getter for height value
         * @return Height value
         */
        unsigned height() const;


        /**
         * @brief Setter for coordinate X value
         * @param x New coordinate X value
         */
        virtual void setX(int x);

        /**
         * @brief Setter for coordinate Y value
         * @param y New coordinate Y value
         */
        virtual void setY(int y);

        /**
         * @brief Setter for height value
         * @param height New height value
         */
        virtual void setHeight(unsigned height);

        /**
         * @brief Setter for width value
         * @param width New width value
         */
        virtual void setWidth(unsigned width);


        /**
         * @brief Processes control event from virtual gamepad
         * @param code Button key code
         * @return True if processed by this widget
         */
        virtual bool onControl(Control::VirtualGamepad::KeyCode code);


        /// Renders widget via provided renderer
        virtual void render() = 0;
    };
}
