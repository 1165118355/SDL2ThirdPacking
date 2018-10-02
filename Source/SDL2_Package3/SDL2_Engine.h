///////////////////////////////
//	this class is a Engin in SDL2.start of the program from here
//	��������￪ʼ
//	������
//	2018��6��23�� 23:50:52
//	by	ˮ������

#ifndef _SDL2_ENGINE_H_BOX
#define _SDL2_ENGINE_H_BOX
#include <SDL2/SDL.h>
#include <SDL2_SceneManager.h>
#include <SDL2_Package.h>
#include <SDL2_Renderer.h>
#include <SDL2_MainWindow.h>
#include <SDL2_FontSystem.h>


/*
����ô���ģʽ�����ڲ������װ����
*/
namespace WaterBox
{
	class SDL2_Engine
	{
	public :
		/*
		*	\brief	����ģʽ��ȡʵ��
		*
		*	\return	��������ʵ�� 
		*/
		static SDL2_Engine *get();

		/*
		*	\brief ��������
		*
		*/
		void StartEngine();

		/*
		*	\brief	�õ���Ⱦ��ʵ��
		*	
		*	\return	��Ⱦ��ʵ��
		*/
		SDL_Renderer *getRenderer();

		void setFPS(int fps);
	private :
		static SDL2_Engine *mEngine;
		int m_FPS;
	private:
		SDL2_Engine();
		void limitFPS(int maxFPS);

	};
}
#endif	//	!_SDL2_ENGINE_H_BOX