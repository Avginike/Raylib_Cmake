#include <raylib.h>

int scalefactor = 2;
int screenWidth = 256 * scalefactor;
int screenHeight = 240 * scalefactor;

bool ShouldWindowClose = false;

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Project Slime");

    while(!ShouldWindowClose)    // Detect window close button or ESC key
    {
        ShouldWindowClose = WindowShouldClose();
        

    


    }
}