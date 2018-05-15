#include "SDL2_SceneManager.h"
using namespace WaterBox;
SDL2_Scene * WaterBox::SDL2_SceneManager::createScene(std::string name)
{
	return new SDL2_Scene;
}

WaterBox::SDL2_SceneManager::SDL2_SceneManager()
{

}
