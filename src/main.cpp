#include <raylib.h>


#include "structures/Scene.hpp"
#include "Menus/MainMenu.hpp"
#include "main.hpp"

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


    Scene::SetEnterScene(std::make_unique<MainMenu>());
    TextProperty::MainFont = LoadFont(ASSETS_PATH "Roboto.ttf");

    while(!ShouldWindowClose)    // Detect window close button or ESC key
    {
        ShouldWindowClose = WindowShouldClose();

        Scene::UpdateCurrentScene();

        if(IsKeyPressed(KEY_MINUS) && scalefactor > 1)
        {
            scalefactor--;
            UpdateScreen();
        }
        if(IsKeyPressed(KEY_EQUAL))
        {
            scalefactor++;
            UpdateScreen();
        }


        BeginDrawing();
            
            Scene::RenderCurrentScene();

        EndDrawing();
    }
}

void UpdateScreen()
{
    screenWidth = 256 * scalefactor;
    screenHeight = 240 * scalefactor;
    SetWindowSize(screenWidth, screenHeight);
}