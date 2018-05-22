#ifndef _SDL2_RENDERER_H_BOX
#define _SDL2_RENDERER_H_BOX
#include <SDL2/SDL.h>
#include <SDL2_Engine.h>

/*
渲染器封装，将它独立于SDL2_Engine类
*/

namespace WaterBox 
{
	class SDl2_Engine;
	class SDL2_Renderer
	{
	public :

		friend class SDL2_Engine;
	private :
		/*他返回一个实例*/
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