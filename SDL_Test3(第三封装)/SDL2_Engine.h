#pragma once
#include <SDL2_SceneManager.h>
#include <SDL2_Package.h>
/*
这个用代理模式，将内部的类封装起来
*/
namespace WaterBox
{
	class SDL2_Engine
	{
	public :
		/*
		*	\brief	单例模式获取实例
		*
		*	\return	返回引擎实例 
		*/
		static SDL2_Engine *get();

		/*
		*	\brief 获取场景管理器实例
		*
		*	\return	返回场景管理器实例
		*/
		SDL2_SceneManager *getSceneManager() { return mSceneManager; }
	private :
		SDL2_SceneManager *mSceneManager;
		SDL2_Package *mPackage;
		static SDL2_Engine *mengine;
		SDL2_Engine();

	};
}