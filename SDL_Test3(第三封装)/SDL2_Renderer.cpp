#include "SDL2_Renderer.h"

using namespace WaterBox;
SDL_Window *SDL2_Renderer::mwin = NULL;
SDL_Renderer *SDL2_Renderer::mrend = NULL;
SDL2_Renderer *SDL2_Renderer::mrend2 = NULL;


SDL2_Renderer *SDL2_Renderer::get()
{
	if (NULL == mrend)
	{
		if (NULL == mwin)
		{
			return NULL;
		}
		mrend2 = new SDL2_Renderer(mwin);
		
	}
	return mrend2;
}

WaterBox::SDL2_Renderer::SDL2_Renderer(SDL_Window * win)
{
	mrend = SDL_CreateRenderer(mwin, -1, 1);
}
