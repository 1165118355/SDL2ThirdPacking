#include "SDL2_SceneManager.h"
using namespace WaterBox;

void WaterBox::SDL2_SceneManager::switchScene(SDL2_Scene * scene)
{
	if (scene != NULL)
	{
		delete mScene;
	}
	mScene = scene;
	mScene->bindGui(SDL2_Gui::get());
}

WaterBox::SDL2_SceneManager::SDL2_SceneManager()
{

}
