#ifndef _SDL2_RENDERER_H_BOX
#define _SDL2_RENDERER_H_BOX
#include <SDL2/SDL.h>
#include <SDL2_Engine.h>

/*
��Ⱦ����װ������������SDL2_Engine��
*/

namespace WaterBox 
{
	class SDl2_Engine;
	class SDL2_Renderer
	{
	public :

		/*������һ��ʵ��*/
		static SDL2_Renderer *get();
		SDL_Renderer *getRenderer() { return mrend;}
		static void setWindow(SDL_Window *win) { mwin = win; }

	private:
		SDL2_Renderer(SDL_Window *win); 

	private:
		friend class SDL2_Engine;
		static SDL_Window *mwin;
		static SDL_Renderer *mrend;
		static SDL2_Renderer *mrend2;
	};
}
#endif// !_SDL2_RENDERER_H_BOX