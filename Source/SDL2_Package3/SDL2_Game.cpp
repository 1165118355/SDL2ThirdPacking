#include "SDL2_Game.h"

SDL2_Game *SDL2_Game::m_Instance = nullptr;


SDL2_Game * SDL2_Game::get()
{
	if(nullptr == m_Instance)
	{
		m_Instance = new SDL2_Game();
	}
	return m_Instance;
}

float SDL2_Game::getIFPS()
{
	return m_IFPS;
}

SDL2_Game::SDL2_Game()
{
	m_IFPS = 0;
	m_MaxFPS = 0;
	m_Time = 0;
}


SDL2_Game::~SDL2_Game()
{
}

void SDL2_Game::init()
{
}

void SDL2_Game::update()
{
	Uint32 nowTime =  SDL_GetTicks();
	m_IFPS = nowTime - m_Time;
	float delayTime = 1000.0f / m_MaxFPS - m_IFPS;
	if(delayTime >= 0)
	{
		SDL_Delay(delayTime);
	}
	nowTime = SDL_GetTicks();
	m_IFPS = (nowTime - m_Time)/1000.0f;
	m_Time = nowTime;
}

