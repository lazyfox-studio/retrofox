#include "interface/button.h"

Interface::Button::Button(const Graphics::Sprite& sprite_default, 
    const Graphics::Sprite& sprite_clicked, const Graphics::Sprite& sprite_hovered, 
    const Graphics::Sprite& sprite_disabled)
    : state(Default), 
    sprites{ sprite_default, sprite_clicked, sprite_hovered, sprite_disabled }
{
}

Interface::Button::Button(const Graphics::Sprite& sprite_default, const Graphics::Sprite& sprite_clicked)
    : Button(sprite_default, sprite_clicked, sprite_default, sprite_default)
{
}

void Interface::Button::setState(State new_state)
{
    state = new_state;
}

void Interface::Button::render(Renderer& renderer)
{
    renderer.draw(sprites + static_cast<int>(state));
}
