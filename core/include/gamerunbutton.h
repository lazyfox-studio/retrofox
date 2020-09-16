#pragma once

#include "interface/labeledbutton.h"

#include <iostream>
#include <string>

#include <database.h>

class GameRunButton : public Interface::LabeledButton
{
protected:
    Database::Entities::Game m_game;

public:
    GameRunButton(
        SDL_Renderer* renderer,
        Database::Entities::Game game,
        const std::string& path_default,
        const std::string& path_clicked,
        const std::string& path_hovered,
        const std::string& path_disabled
    );

    GameRunButton(SDL_Renderer* renderer, Database::Entities::Game game, const std::string& path_default,
        const std::string& path_clicked);

    ~GameRunButton() = default;

    virtual void onClick();
};