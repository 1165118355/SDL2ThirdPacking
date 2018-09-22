#include "SDL2_Renderer.h"

using namespace WaterBox;
SDL_Window *SDL2_Renderer::m_Win = NULL;
SDL_Renderer *SDL2_Renderer::m_Rend = NULL;
SDL2_Renderer *SDL2_Renderer::m_Rend2 = NULL;


SDL2_Renderer *SDL2_Renderer::get()
{
	if (NULL == m_Rend)
	{
		if (NULL == m_Win)
		{
			return NULL;
		}
		m_Rend2 = new SDL2_Renderer(m_Win);
		
	}
	return m_Rend2;
}

SDL_Renderer * WaterBox::SDL2_Renderer::getRenderer()
{
	return m_Rend;
}

void WaterBox::SDL2_Renderer::setRenderer(SDL_Renderer * rend)
{
	m_Rend = rend;
}

void WaterBox::SDL2_Renderer::backMainRenderer()
{
	m_Rend = m_MainRend;
}

WaterBox::SDL2_Renderer::SDL2_Renderer(SDL_Window * win)
{
	m_MainRend = SDL_CreateRenderer(m_Win, -1, 1);
	m_Rend = m_MainRend;
	SDL_SetRenderDrawBlendMode(m_Rend, SDL_BLENDMODE_BLEND);//			设置渲染混合模式（添加透明度渲染）
}
