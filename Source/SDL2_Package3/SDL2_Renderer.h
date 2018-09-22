///////////////////////////////
//	this class is a Renderer in SDL2.
//	用来渲染（其实就是为了方便调用所以弄成了单例模式）
//	《渲染类》
//	2018年6月24日 00:14:19
//	by	水华宝箱

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
		///	brief	返回一个实例
		static SDL2_Renderer *get();

		///	brief	返回SDL渲染器
		SDL_Renderer *getRenderer();

		///	\brief	设置渲染器
		void setRenderer(SDL_Renderer *rend);
		void backMainRenderer();

		///	brief	设置窗口（引擎内部使用）
		static void setWindow(SDL_Window *win) { m_Win = win; }

	private:
		SDL2_Renderer(SDL_Window *win); 

	private:
		friend class SDL2_Engine;					//	它和引擎类是好朋友
		static SDL_Window *m_Win;					//	临时存储窗口
		static SDL_Renderer *m_Rend;				//	SDL渲染器
		SDL_Renderer *m_MainRend;
		static SDL2_Renderer *m_Rend2;				//	单例返回的渲染器
	};
}
#endif// !_SDL2_RENDERER_H_BOX