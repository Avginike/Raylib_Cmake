#include "MainMenu.hpp"

#include "structures/Menu.hpp"

#include <iostream>

namespace Game
{
    
    void MainMenu::Start()
    {
        Buttons.push_back(Button(Vector2{(float)GetScreenWidth() / 2 - 100, (float)GetScreenHeight() / 2 - 50}, Vector2{200, 50}, WHITE, [&](){ std::cout << "Start" << std::endl; }));
    }
}