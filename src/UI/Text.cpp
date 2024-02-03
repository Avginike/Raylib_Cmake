#include <raylib.h>
#include <raymath.h>
#include <string>

#include "Text.hpp"
#include "UIElement.hpp"
#include "main.hpp"

namespace Game
{
    
    
    Text::Text(Vector2 pos, std::string str, int fontSize): UIElement(pos),Properties(str)
    {
        Properties.fontSize = fontSize;
    }
    
    Text::Text(Vector2 pos, std::string str): UIElement(pos),Properties(str){}

    Text::Text(Vector2 position,std::string str, int fontSize, Color col): UIElement(position),Properties(str)
    {
        Properties.fontSize = fontSize;
        Properties.color = col;
    }
    void Text::Render()
    {
        DrawTextEx(*(Properties.font), Properties.text.c_str(), Vector2Scale(position, scalefactor),Properties.fontSize * scalefactor,spacing, Properties.color);
    }
    void Text::RenderCentered()
    {
        auto TextSize = MeasureTextEx(*(Properties.font), Properties.text.c_str(), Properties.fontSize * scalefactor,spacing);

        DrawTextEx(*(Properties.font), Properties.text.c_str(), 
        Vector2{(position.x - TextSize.x / 2) * scalefactor , (position.y - TextSize.y  / 2) * scalefactor}, 
        Properties.fontSize * scalefactor,spacing, Properties.color);
    }

} 
