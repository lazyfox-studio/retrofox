#pragma once

#include "interface/widget.h"

#include <list>

namespace Interface
{
    using WidgetRefList = std::list<std::reference_wrapper<Interface::Widget>>;

    /**
     * @brief Layout widget
     * @details Class to represent multiple widgets arranged in a horizontal 
     * or vertical stack called 'layout' (with automated aligning and padding)
    */
    class Layout : public Widget
    {
    protected:
        /// List of references to widgets
        WidgetRefList widgets;

    public:
        /// Represents margin size
        struct Margin
        {
            int left;   ///< Left margin
            int top;    ///< Top margin
            int right;  ///< Right margin
            int bottom; ///< Bottom margin
        };
        Margin margin; ///< Widgets margin

        /// Represents spacing size
        struct Spacing
        {
            int vertical;   ///< Vertical spacing
            int horizontal; ///< Horizontal spacing
        };
        Spacing spacing; ///< Widgets spacing

        /// Represents type of stacking
        enum class Stacking
        {
            Vertical,  ///< Vertical stacking
            Horizontal ///< Horizontal stacking
        };
        Stacking stacking; ///< Widgets stacking type

        /// Default constructor
        Layout();

        /**
         * @brief Constructor-initializer
         * @param x Coordinate X value
         * @param y Coordinate Y value
         * @param height Height value
         * @param width Width value
         */
        Layout(int x, int y, unsigned height, unsigned width);

        /// Destructor
        ~Layout();


        /**
         * @brief Adds widget to front of list
         * @param widget Widget to add
         */
        void pushFront(Widget& widget);

        /**
         * @brief Adds widget to back of list
         * @param widget Widget to add
         */
        void pushBack(Widget& widget);

        /// Removes first widget from list
        void popFront();

        /// Removes last widget from list
        void popBack();

        /// Removes all widgets from list
        void clear();


        /// Renders all widgets in list
        virtual void render();

        /// Recalculates widget parameters
        void update();
    };
}
