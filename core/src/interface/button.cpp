#include "interface/button.h"

Interface::Button::Button(const Graphics::Sprite& sprite_default, 
    const Graphics::Sprite& sprite_clicked, const Graphics::Sprite& sprite_hovered, 
    const Graphics::Sprite& sprite_disabled)
    : state(Default), 
    sprites{ sprite_default, sprite_clicked, sprite_hovered, sprite_disabled }
{
}

void Interface::Button::setState(State new_state)
{
    state = new_state;
}

Graphics::Sprite* Interface::Button::getSprite()
{
    return sprites + static_cast<int>(state);
}
