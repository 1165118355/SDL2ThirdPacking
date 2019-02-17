#include "SDL2_System.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2_MainWindow.h>
#include <SDL2_Utils.h>
#include <SDL2_Gui.h>
#include <SDL2_FontSystem.h>
#include <SDL2_Renderer.h>
#include <SDL2_Console.h>
#include <SDL2_Event.h>
#include <SDL2_Game.h>

using namespace WaterBox;

SDL2_System *SDL2_System::m_Instance = nullptr;

SDL2_System::SDL2_System()
{
	m_NowScene = nullptr;
	m_Event = new SDL_Event();
	m_SceneManager = new SDL2_SceneManager();
}


SDL2_System * SDL2_System::get()
{
	if (nullptr == m_Instance)
	{
		m_Instance = new SDL2_System();
	}
	return m_Instance;
}

void SDL2_System::init()
{
	TTF_Init();
	SDL2_FontSystem::get()->createFont("../Data/Font/font.ttf", "SystemFont", 20);

	SDL2_Gui::get()->clear();
	SDL2_Gui::get()->addComponent(SDL2_MainWindow::get()->getSDL2Window());
	SDL2_Utils::get()->setWinSize(SDL2_MainWindow::get()->getSize());

}

void SDL2_System::update()
{
	SDL2_Game::get()->update();
	SDL2_Utils::get()->setWinSize(SDL2_MainWindow::get()->getSize());
	SDL2_Event::get()->update();
	while (SDL_PollEvent(m_Event))
	{
		SDL2_Event::get()->updateEvent(m_Event);
		SDL2_Gui::get()->updateEvent(m_Event);
		SDL2_Console::get()->updateEvent(m_Event);
	}
	SDL2_Console::get()->update(m_Event);
	SDL2_Gui::get()->update(m_Event);
	if (m_NowScene != m_SceneManager->getScene())
	{
		m_NowScene = m_SceneManager->getScene();
		m_NowScene->init();
	}
	if (m_NowScene != nullptr)
	{
		m_NowScene->update();
	}
}

void WaterBox::SDL2_System::render()
{
	SDL_RenderClear(SDL2_Renderer::get()->getRenderer());
	if (m_NowScene != nullptr)
	{
		m_NowScene->render();
	}
	SDL2_Gui::get()->show();
	SDL2_Console::get()->show();
	SDL_RenderPresent(SDL2_Renderer::get()->getRenderer());
}

void SDL2_System::shutdown()
{
}

SDL2_System::~SDL2_System()
{
}
