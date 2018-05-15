#pragma once
#include <SDL2_SceneManager.h>
#include <SDL2_Package.h>
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
		*	\brief ��ȡ����������ʵ��
		*
		*	\return	���س���������ʵ��
		*/
		SDL2_SceneManager *getSceneManager() { return mSceneManager; }
	private :
		SDL2_SceneManager *mSceneManager;
		SDL2_Package *mPackage;
		static SDL2_Engine *mengine;
		SDL2_Engine();

	};
}