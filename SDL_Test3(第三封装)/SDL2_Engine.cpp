#include "SDL2_Engine.h"

using namespace WaterBox;
SDL2_Engine *mengine = nullptr;

SDL2_Engine * WaterBox::SDL2_Engine::get()
{
	if (mengine == nullptr)
	{
		mengine = new SDL2_Engine();
	}
	return mengine;
}

WaterBox::SDL2_Engine::SDL2_Engine()
{
	mPackage = new SDL2_Package();
	mSceneManager = new SDL2_SceneManager();
}
