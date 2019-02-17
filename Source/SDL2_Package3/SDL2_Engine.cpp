#include "SDL2_Engine.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2_MainWindow.h>
#include <SDL2_Utils.h>
#include <SDL2_System.h>

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
	SDL2_MainWindow::get()->getSDL2Window()->getWindow();
	SDL2_MainWindow::get();
	SDL2_Gui::get();
	SDL2_Renderer::get();

	SDL2_System::get()->init();
	while (true)
	{
		SDL2_System::get()->update();
		SDL2_System::get()->render();
	}
	SDL2_System::get()->shutdown();
	
}

SDL_Renderer * WaterBox::SDL2_Engine::getRenderer()
{
	SDL_Renderer *rend = SDL2_Renderer::get()->getRenderer();
	return rend;
}

SDL2_Engine::SDL2_Engine()
{
	//mPackage = new SDL2_Package();
}
