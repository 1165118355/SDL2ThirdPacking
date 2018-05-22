#ifndef _SDL2_ENGINE_H_BOX
#define _SDL2_ENGINE_H_BOX
#include <SDL2/SDL.h>
#include <SDL2_SceneManager.h>
#include <SDL2_Package.h>
#include <SDL2_Renderer.h>
#include <SDL2_Window.h>

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
		*	\brief ��ȡ����������ʵ��
		*
		*	\return	���س���������ʵ��
		*/
		SDL2_SceneManager *getSceneManager(){ return mSceneManager;}

		/*
		*	\brief	�õ���Ⱦ��ʵ��
		*	
		*	\return	��Ⱦ��ʵ��
		*/
		SDL_Renderer *getRenderer();
	private :
		SDL2_SceneManager *mSceneManager;
		SDL2_Window *mWindow;
		SDL_Renderer *rend;
		
		static SDL2_Engine *mEngine;
		
	private:
		SDL2_Engine();

	};
}
#endif	//	!_SDL2_ENGINE_H_BOX