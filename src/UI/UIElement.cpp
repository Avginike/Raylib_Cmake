#include "UIElement.hpp"

namespace Game
{
    void UIElement::Render(UIElement &Element) 
    {
        Element.Render();
    }
    void UIElement::Update(UIElement &Element)
    {
        Element.Update();
    }
} // namespace BlatFormer
