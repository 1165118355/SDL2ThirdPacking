///////////////////////////////
//	this class is a Renderer in SDL2.
//	������Ⱦ����ʵ����Ϊ�˷����������Ū���˵���ģʽ��
//	����Ⱦ�ࡷ
//	2018��6��24�� 00:14:19
//	by	ˮ������

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
		///	brief	����һ��ʵ��
		static SDL2_Renderer *get();

		///	brief	����SDL��Ⱦ��
		SDL_Renderer *getRenderer() { return m_Rend;}

		///	brief	���ô��ڣ������ڲ�ʹ�ã�
		static void setWindow(SDL_Window *win) { m_Win = win; }

	private:
		SDL2_Renderer(SDL_Window *win); 

	private:
		friend class SDL2_Engine;					//	�����������Ǻ�����
		static SDL_Window *m_Win;					//	��ʱ�洢����
		static SDL_Renderer *m_Rend;				//	SDL��Ⱦ��
		static SDL2_Renderer *m_Rend2;				//	�������ص���Ⱦ��
	};
}
#endif// !_SDL2_RENDERER_H_BOX