#pragma once
#include <raylib.h>
#include <string>
#include <functional>

#include "UIElement.hpp"
#include "Text/TextProperty.hpp"   
using namespace std;

namespace Game
{
    

    class Button : public UIElement
    {
        float ButtonScale{1};
        float sizex;
        float sizey;
        
        public:

            TextProperty Label{};
            std::function<void()> OnClickEvent;
            Color color = BLACK;
            
            
           
        void Update();
        void Update(std::function<void()> ClickEvent);
        void Update(std::function<void(Button&)> ClickEvent);
        void Render();
        

        Button() = default;
        
        Button(Vector2 position, Vector2 siz, Color col, std::function<void()> OnClickEvent): UIElement(position,siz),color(col),OnClickEvent(OnClickEvent){};
        
    };
}