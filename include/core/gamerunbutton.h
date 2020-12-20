#pragma once

#include "core/interface/labeledbutton.h"

#include <iostream>
#include <string>

#include <database/database.h>

class GameRunButton : public Interface::LabeledButton
{
protected:
    Entities::Game m_game;

public:
    GameRunButton(
        SDL_Renderer* renderer,
        Entities::Game game,
        const std::string& path_default,
        const std::string& path_clicked,
        const std::string& path_hovered,
        const std::string& path_disabled
    );

    GameRunButton(SDL_Renderer* renderer, Entities::Game game, const std::string& path_default,
        const std::string& path_clicked);

    ~GameRunButton() = default;

    virtual void onClick();
};