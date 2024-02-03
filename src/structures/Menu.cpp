#include <algorithm>

#include "Menu.hpp"
#include "Scene.hpp"

namespace Game
{
    void Menu::Render() 
    {
        void(*func)(UIElement&) = UIElement::Render;

        for_each(Buttons.begin(),Buttons.end(),func);
        for_each(Labels.begin(),Labels.end(),func);
    }
    void Menu::Update() 
    {
        void(*func)(UIElement&) = UIElement::Update;

        for_each(Buttons.begin(),Buttons.end(),func);
        for_each(Labels.begin(),Labels.end(),func);

        if(IsKeyPressed(KEY_ESCAPE))
        {
            Scene::ExitScene();
        }
    }
}