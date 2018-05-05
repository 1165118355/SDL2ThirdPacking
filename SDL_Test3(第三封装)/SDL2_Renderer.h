#ifndef _SDL2_RENDERER_BOX
#define _SDL2_RENDERER_BOX
#include <SDL2/SDL.h>

/*
��ʹ�õ���ģʽ
*/

namespace WaterBox 
{
	class SDL2_Renderer
	{
	public :
		/*������һ��ʵ��*/
		static SDL2_Renderer *get();
		static void setWindow(SDL_Window *win) { mwin = win; }
	private :
		SDL2_Renderer(SDL_Window *win); 
		static SDL_Window *mwin;
		static SDL_Renderer *mrend;
		static SDL2_Renderer *mrend2;
	};
}
#endif// !_SDL2_RENDERER_BOX