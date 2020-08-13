#include "window.h"

Window::Window()
{
    window = SDL_CreateWindow("Retrofox", 100, 100, 800, 600, SDL_WINDOW_HIDDEN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Window::show()
{
    SDL_ShowWindow(window);
}

void Window::start()
{
    /*Interface::LabeledButton button(renderer, "Test", "../../core/data/testsprite.bmp", "../../core/data/testsprite2.bmp");
    Interface::LabeledButton button2(renderer, "Enjoy", "../../core/data/testsprite.bmp", "../../core/data/testsprite2.bmp");

    Interface::Layout layout(5, 5, 400, 400);
    button.base_size.height = 100;
    button.size_policy.vertical = Interface::Button::SizePolicy::Fixed;
    layout.pushBack(button);
    layout.pushBack(button2);

    Interface::Label label(renderer, Graphics::FontBuffer::instance().load("../../core/data/roboto-regular.ttf", 40), 0, 0, "Hello world");
    label.setHeight(50);
    label.setWidth(500);*/
    GameMenu menu(5, 5, 500, 700, 80);
    menu.showGames(renderer, "testbase.db");
    menu.reset();

    Interface::Paragraph para(renderer, Graphics::FontBuffer::instance().load("../../core/data/roboto-regular.ttf", 20), 100, 100, 180, "Some very longgggggg line of text... Somee veeeery llong line of text...");

    SDL_Event event;
    while (true)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return;
            }
            else
            {
                Control::VirtualGamepad::KeyCode key_code = Control::VirtualGamepad::instance().processInput(event);
                if (key_code != Control::VirtualGamepad::KeyCode::empty)
                {
                    //root.onClick();
                }
            }
        }


        SDL_RenderClear(renderer);
        menu.render();
        //layout.render();
        //label.render();
        //para.render();
        SDL_RenderPresent(renderer);
    }
}