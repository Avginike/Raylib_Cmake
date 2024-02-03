#include "MainMenu.hpp"

#include "structures/Menu.hpp"

#include <iostream>
#include "main.hpp"

namespace Game
{
    
    void MainMenu::Start()
    {
        Buttons.push_back(Button(Vector2{(float)screenWidth / 2, (float)screenWidth / 2}, Vector2{100, 25}, WHITE, [&](){ std::cout << "Start" << std::endl; }));
        Buttons.back().Label = TextProperty("Start", &TextProperty::MainFont, BLACK);
        Buttons.push_back(Button(Vector2{(float)screenWidth / 2, (float)screenHeight / 2 + 50}, Vector2{100, 25}, WHITE, [&](){ std::cout << "Editor" << std::endl; }));
        Buttons.back().Label = TextProperty("Editor", &TextProperty::MainFont, BLACK);

        float size = MeasureText("Project", 40);
        size /= 2;
        Labels.push_back(Text(Vector2{(float)screenWidth / 2 - size + 10, (float)screenHeight / 2 - 100}, "Project", 40,BLACK));
        size = MeasureText("Slime", 40);
        size /= 2;
        Labels.push_back(Text(Vector2{(float)screenWidth / 2 - size, (float)screenHeight / 2 - 75}, "Slime", 40,GREEN));
   
    }
}