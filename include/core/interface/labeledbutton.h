#pragma once

#include "core/interface/button.h"

#include <string>

#include "core/interface/label.h"

namespace Interface
{
    /**
     * @brief Labeled button widget
     * @details Class to represent 'clickable' button with text label
     */
    class LabeledButton : public Button
    {
    protected:
        /// Button text container widget
        Interface::Label label;

    public:
        /**
         * @brief Constructor-initializer (with each state)
         * @param renderer Renderer
         * @param text Text on button
         * @param path_default Path to texture for default button state
         * @param path_clicked Path to texture for clicked button state
         * @param path_hovered Path to texture for hovered button state
         * @param path_disabled Path to texture for disabled button state
         */
        LabeledButton(
            SDL_Renderer* renderer,
            const std::string& text,
            const std::string& path_default,
            const std::string& path_clicked,
            const std::string& path_hovered,
            const std::string& path_disabled
        );

        /**
         * @brief Constructor-initializer (with important states only)
         * @param renderer Renderer
         * @param text Text on button
         * @param path_default Path to texture for default button state
         * @param path_clicked Path to texture for clicked button state
         */
        LabeledButton(
            SDL_Renderer* renderer, 
            const std::string& text, 
            const std::string& path_default, 
            const std::string& path_clicked
        );

        /// Default destructor
        ~LabeledButton() = default;

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

        /// Renders button via provided renderer
        virtual void render();
    };
}
