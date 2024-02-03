#include <raylib.h>
#include <raymath.h>

#include "main.hpp"

#include "button.hpp"


namespace Game
{
    void Button::Update() 
    {
        Update(OnClickEvent);
    }
    void Button::Update(std::function<void(Button&)> ClickEvent) 
    {

        double k = 10 * GetFrameTime();

        if(CheckCollisionPointRec(GetMousePosition(), {(position.x  - sizex / 2) * scalefactor, (position.y - sizey / 2) * scalefactor, sizex * scalefactor, sizey * scalefactor}))
        {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                ClickEvent(*this);
            }

            ButtonScale = Lerp(ButtonScale, 1.2, k);
        }
        else
            ButtonScale = Lerp(ButtonScale, 1, k);
            
    }
    void Button::Update(std::function<void()> ClickEvent)
    {
        Update([&](Button&){ClickEvent();});
    }

    void Button::Render()
    {
        sizex = size.x * ButtonScale;
        sizey = size.y * ButtonScale;

        Rectangle ScaledRectangle = Rectangle{
            (position.x  - sizex / 2) * scalefactor, 
            (position.y - sizey / 2) * scalefactor, 
            size.x * ButtonScale * scalefactor,
             size.y * ButtonScale * scalefactor};

        DrawRectangleRounded(ScaledRectangle,0.25,10, color);
        DrawRectangleRoundedLines(ScaledRectangle,0.25,10,2, WHITE);

        if(Label.text != "")
        {
            Vector2 TextSize = MeasureTextEx(*(Label.font), Label.text.c_str(), Label.fontSize * ButtonScale,Label.spacing);
            TextSize = Vector2Scale(TextSize, 0.5);

            DrawTextEx(*(Label.font), Label.text.c_str(),Vector2Scale(Vector2Subtract(position,TextSize),scalefactor),Label.fontSize * ButtonScale * scalefactor,Label.spacing, Label.color);
        }
    }

    


} // namespace BlatFormer
