#include <vector>
#include <cstdint>
#include <string>
#include <stack>
#include <memory>
#include "Scene.hpp"


namespace Game {

    std::stack<std::unique_ptr<Scene>> Scene::SceneStack = std::stack<std::unique_ptr<Scene>>();
    bool Scene::GameHasToExit = false;
    void Scene::SetEnterScene(std::unique_ptr<Scene> mode) 
    {
        SceneStack.push(std::move(mode));
        SceneStack.top()->Start();

    }
    void Scene::PushScene(std::unique_ptr<Scene> mode) 
    {
        End();
        SceneStack.push(std::move(mode)); 
        SceneStack.top()->Start();
    }
    void Scene::ExitScene()
    {
        End();


        if(SceneStack.size() > 1)
        {
            SceneStack.pop();
        }
        else
        {
            ExitGame();
        }
       
    }
    void Scene::RenderCurrentScene() 
    {
        ClearBackground(SceneStack.top()->Background);
        SceneStack.top()->Render();
    }
    void Scene::UpdateCurrentScene() 
    {
        SceneStack.top()->Update();
    }
    void Scene::ExitGame()
    {
        GameHasToExit = true;
    }
    
}