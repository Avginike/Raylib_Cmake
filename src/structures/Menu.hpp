#pragma once

#include "Scene.hpp"
#include "UI/Text.hpp"
#include "UI/Button.hpp"

#include <vector>


namespace Game
{
    class Menu : public Scene
    {
        

        public:
            std::vector<Button> Buttons;
            std::vector<Text> Labels;
            
            
        virtual void Render();
        virtual void Update();
     

    };
}