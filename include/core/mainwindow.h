#pragma once

#include "interface/window.h"

#include <SDL.h>

#include "gamemenu.h"

/**
 * @ingroup core
 * @brief Main window of application
 * @details Class to represent main window of application
 */
class MainWindow : public Interface::Window
{
public:
    /// Default constructor is not provided
    MainWindow() = delete;

    /**
     * @brief Constructor-initializer
     * @param title Window title
     * @param x Coordinate X value
     * @param y Coordinate Y value
     * @param width Width value
     * @param height Height value
     */
    MainWindow(const std::string& title, int x, int y, int width, int height);

    /// Destructor
    ~MainWindow();

    /// Initializes window
    virtual void initialize();
};
