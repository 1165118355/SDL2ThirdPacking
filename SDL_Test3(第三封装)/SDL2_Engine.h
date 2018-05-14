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
		static SDL2_Engine *get();
		SDL2_SceneManager *getScneManager() { return mSceneManager; }
	private :
		SDL2_SceneManager *mSceneManager;
		SDL2_Package *mPackage;
		static SDL2_Engine *mengine;
		SDL2_Engine();

	};
}