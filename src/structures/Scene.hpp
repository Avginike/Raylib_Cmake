#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include <stack>
#include <memory>

#include <raylib.h>

namespace Game
{
    class Scene
    {
        static std::stack<std::unique_ptr<Scene>> SceneStack;

        Color Background = {0,0,0,255};

        public:
            static bool GameHasToExit;
            static void ExitGame();
            

            static void SetEnterScene(std::unique_ptr<Scene> Scene);



            virtual void Render(){}
            virtual void Update(){}

           
            virtual void Start(){}
            virtual void End(){}

            void PushScene(std::unique_ptr<Scene> Scene);
            void ExitScene();

            static void UpdateCurrentScene();
            static void RenderCurrentScene();
            
           
    };
}