#include "SDL2_Engine.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2_MainWindow.h>

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
	SDL2_Renderer::setWindow(SDL2_MainWindow::get()->getSDL2Window()->getWindow());
	SDL2_Gui::get();
	SDL2_Renderer::get();
	SDL2_MainWindow::get();
	while (true)
	{
		SDL2_Gui::get()->clear();
		SDL2_Gui::get()->addComponent(SDL2_MainWindow::get()->getSDL2Window());
		mSceneManager->getScene()->init();
		while (true)
		{
			SDL_RenderClear(SDL2_Renderer::get()->getRenderer());
			mSceneManager->getScene()->update();
			mSceneManager->getScene()->render();
			SDL2_Gui::get()->update(nullptr);
			SDL_RenderPresent(SDL2_Renderer::get()->getRenderer());
			limitFPS(m_FPS);
		}
	}
}

SDL_Renderer * WaterBox::SDL2_Engine::getRenderer()
{
	SDL_Renderer *rend = SDL2_Renderer::get()->getRenderer();
	return rend;
}

void WaterBox::SDL2_Engine::setFPS(int fps)
{
	m_FPS = fps;
}

SDL2_Engine::SDL2_Engine()
{
	//mPackage = new SDL2_Package();
	m_FPS = 60;
	mSceneManager = new SDL2_SceneManager();
	TTF_Init();
	SDL2_FontSystem::get()->createFont("../Data/Font/font.ttf", "SystemFont", 20);
}

Uint32 beforTime=0;
void WaterBox::SDL2_Engine::limitFPS(int maxFPS)
{
	Uint32 time = SDL_GetTicks();

	if (time-beforTime < 1000/ maxFPS)
	{
		SDL_Delay(1000/ maxFPS - (time-beforTime));
	}
	beforTime = time;
}
