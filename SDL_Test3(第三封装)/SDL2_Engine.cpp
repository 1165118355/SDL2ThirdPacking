#include "SDL2_Engine.h"

using namespace WaterBox;
SDL2_Engine *SDL2_Engine::mEngine = nullptr;

SDL2_Engine *SDL2_Engine::get()
{
	if (mEngine == nullptr)
	{
		mEngine = new SDL2_Engine();
	}
	return mEngine;
}

void SDL2_Engine::StartEngine()
{
	mWindow = new SDL2_Window();
	SDL2_Renderer::setWindow(mWindow->getWindow());
	SDL2_Gui::get();
	SDL2_Renderer::get();
	while (true)
	{
		SDL2_Gui::get()->clear();

		SDL2_Gui::get()->clear();
		mSceneManager->getScene()->init();
		while (true)
		{
			mSceneManager->getScene()->update();
		}
	}
}

SDL_Renderer * WaterBox::SDL2_Engine::getRenderer()
{
	SDL_Renderer *rend = SDL2_Renderer::get()->getRenderer();
	return rend;
}

SDL2_Engine::SDL2_Engine()
{
	//mPackage = new SDL2_Package();
	mSceneManager = new SDL2_SceneManager();
}
