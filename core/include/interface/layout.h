#pragma once

#include "interface/widget.h"

#include <list>
#include <memory>

namespace Interface
{
    /// List of widget shared pointers
    using WidgetPtrList = std::list<std::shared_ptr<Widget>>;

    /**
     * @brief Layout widget
     * @details Class to represent multiple widgets arranged in a horizontal 
     * or vertical stack called 'layout' (with automated aligning and padding)
    */
    class Layout : public Widget
    {
    protected:
        /// List of references to widgets
        WidgetPtrList widgets;

        /// Current widget iterator
        WidgetPtrList::iterator current;

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
         * @param widget Widget pointer to add
         */
        void pushFront(std::shared_ptr<Widget> widget);

        /**
         * @brief Adds widget to back of list
         * @param widget Widget pointer to add
         */
        void pushBack(std::shared_ptr<Widget> widget);

        /**
         * @brief Emplaces widget WidgetType to front of list
         * @param ctor_args Constructor arguments
         */
        template<typename WidgetType, typename ...CtorArgTypes>
        std::shared_ptr<WidgetType> emplaceFront(CtorArgTypes ...ctor_args);

        /**
         * @brief Emplaces widget WidgetType to back of list
         * @param ctor_args Constructor arguments
         */
        template<typename WidgetType, typename ...CtorArgTypes>
        std::shared_ptr<WidgetType> emplaceBack(CtorArgTypes ...ctor_args);

        /// Removes first widget from list
        void popFront();

        /// Removes last widget from list
        void popBack();


        /// Removes all widgets from list
        void clear();

        virtual bool onControl(Control::VirtualGamepad::KeyCode code);

        /// Renders all widgets in list
        virtual void render();

        /// Recalculates widget parameters
        void update();
    };

    template<typename WidgetType, typename ...CtorArgTypes>
    inline std::shared_ptr<WidgetType> Layout::emplaceFront(CtorArgTypes ...ctor_args)
    {
        auto widget = std::make_shared<WidgetType>(ctor_args...);
        widgets.push_front(widget);
        return widget;
    }

    template<typename WidgetType, typename ...CtorArgTypes>
    inline std::shared_ptr<WidgetType> Layout::emplaceBack(CtorArgTypes ...ctor_args)
    {
        auto widget = std::make_shared<WidgetType>(ctor_args...);
        widgets.push_back(widget);
        return widget;
    }
}
