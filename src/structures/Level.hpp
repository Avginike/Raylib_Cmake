#include "Scene.hpp"

#include <string>
#include <array>

namespace Game
{
    class Level : public Scene
    {
        std::string path;

        uint8_t StartX;
        uint8_t StartY;

        std::array<std::array<uint8_t,16>,16> Data;
        void LoadLevel();
        void SaveLevel();


        public:
            void Start();
            void Render();
    };
}