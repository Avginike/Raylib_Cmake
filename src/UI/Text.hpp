#pragma once

#include <string>
#include "UIElement.hpp"
#include <raylib.h>
#include "Text/TextProperty.hpp"

namespace Game
{
    class Text: public UIElement
    {
        

        const int spacing = 5;
        public:

            TextProperty Properties{};
            
            
            Text() = default;
            Text(Vector2 position,std::string str, int fontSize,Color col);
            Text(Vector2 position,std::string str, int fontSize);
            Text(Vector2 position, std::string str);
           

            void Render();
            void RenderCentered();
            
    }; 


}  