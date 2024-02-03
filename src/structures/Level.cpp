#include "Level.hpp"
#include "main.hpp"

#include <fstream>


namespace Game
{
    void Level::Start()
    {
        LoadLevel();
    }
    void Level::LoadLevel()
    {
        std::ifstream file(LEVELS_PATH + path, std::ios::in | std::ios::binary);
        
        file >> StartX;
        file >> StartY;

        for(auto &i : Data)
        {
            for(auto &j : i)
            {
                file >> j;
            }
        }
        file.close();
        
    
    }

    void Level::SaveLevel()
    {
        std::ofstream file(LEVELS_PATH + path, std::ios::out | std::ios::binary);

        file << StartX;
        file << StartY;

        for (auto &i : Data)
        {
            for (auto &j : i)
            {
                file << j;
            }
        }
        file.close();

    }
    void Level::Render()
    {
        LevelSizePx = Vector2{Data.size * 8, Data.front().size * 8};
        int padding = 
    }
} // namespace Game
