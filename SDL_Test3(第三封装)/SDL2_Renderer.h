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

		friend class SDL2_Engine;
	private :
		/*������һ��ʵ��*/
		static SDL2_Renderer *get();

		static void setWindow(SDL_Window *win) { mwin = win; }
		SDL_Renderer *getRenderer() { return mrend;}

		SDL2_Renderer(SDL_Window *win); 
		static SDL_Window *mwin;
		static SDL_Renderer *mrend;
		static SDL2_Renderer *mrend2;
	};
}
#endif// !_SDL2_RENDERER_H_BOX