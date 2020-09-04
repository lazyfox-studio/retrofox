#pragma once

#include "interface/menu.h"

#include <memory>
#include <string>

#include <database.h>

#include "interface/labeledbutton.h"

/**
 * @ingroup core
 * @brief Game menu widget
 * @details Class to represent menu with games buttons
 */
class GameMenu : public Interface::Menu
{
protected:

public:
    /// Default constructor is not provided
    GameMenu() = delete;

    /**
     * @brief Constructor-initializer
     * @param x Coordinate X value
     * @param y Coordinate Y value
     * @param height Height value
     * @param width Width value
     * @param button_height Height of each button in menu
     */
    GameMenu(int x, int y, unsigned height, unsigned width, unsigned button_height);

    /// Destructor
    ~GameMenu();

    /**
     * @brief Adds buttons representing games
     * @param renderer Renderer
     * @param db_path Path to database with games data
     */
    void showGames(SDL_Renderer* renderer, const std::string& db_path);
};
