#include <raylib.h>

#include "structures/Scene.hpp"

int scalefactor = 3;
int screenWidth = 256 * scalefactor;
int screenHeight = 240 * scalefactor;

bool ShouldWindowClose = false;
using namespace Game;
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Project");


    Scene::SetEnterScene(std::make_unique<Scene>());

    while(!ShouldWindowClose)    // Detect window close button or ESC key
    {
        ShouldWindowClose = WindowShouldClose();

        Scene::UpdateCurrentScene();

        BeginDrawing();
            
            Scene::RenderCurrentScene();

        EndDrawing();
    }
}