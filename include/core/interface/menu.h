#pragma once

#include "interface/widget.h"

#include "interface/button.h"
#include "interface/layout.h"

namespace Interface
{
    /// List of button shared pointers
    using ButtonPtrList = std::list<std::shared_ptr<Button>>;

    /**
     * @brief Menu with buttons
     * @details Class to represent menu with buttons list
     */
    class Menu : public Widget
    {
    protected:
        /// Layout with buttons
        Interface::Layout layout;

        /// List of buttons
        ButtonPtrList widgets;

        ButtonPtrList::iterator current; ///< Current button iterator
        ButtonPtrList::iterator first;   ///< First button iterator
        ButtonPtrList::iterator last;    ///< Last button iterator

        /// Height of each button
        unsigned m_button_height;

        /// Number of visible buttons at the moment
        size_t visible_buttons_count;

    public:
        /// Default constructor
        Menu();

        /**
         * @brief Constructor-initializer
         * @param x Coordinate X value
         * @param y Coordinate Y value
         * @param height Height value
         * @param width Width value
         * @param button_height Height of each button in menu
         */
        Menu(int x, int y, unsigned height, unsigned width, unsigned button_height);

        /// Destructor
        ~Menu();


        /// Resets internal iterators
        void reset();

        /**
         * @brief Adds button to front of list
         * @param button Button pointer to add
         */
        void pushFront(std::shared_ptr<Button> button);

        /**
         * @brief Adds button to back of list
         * @param button Button pointer to add
         */
        void pushBack(std::shared_ptr<Button> button);


        /**
         * @brief Switches to next button
         * @return True on success
         */
        bool next();

        /**
         * @brief Switches to previous button
         * @return True on success
         */
        bool previous();


        /// Makes widget active
        virtual void setActive();

        /// Makes widget inactive (ignore control events)
        virtual void setInactive();


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


        /// Renders menu via provided renderer
        virtual void render();
    };
}
