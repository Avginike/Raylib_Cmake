#include <vector>
#include <cstdint>
#include <string>
#include <stack>
#include <memory>

namespace Game
{
    class Scene
    {
        static std::stack<std::unique_ptr<Scene>> modeStack;
        

        public:
            static bool GameHasToExit;
            static void ExitGame();
            

            static void SetEnterGameMode(std::unique_ptr<Scene> mode);



            virtual void Render(){}
            virtual void Update(){}

           
            virtual void Start(){}
            virtual void End(){}

            void PushMode(std::unique_ptr<Scene> mode);
            void ExitMode();

            static void UpdateCurrentMode();
            static void RenderCurrentMode();
            
           
    };
}