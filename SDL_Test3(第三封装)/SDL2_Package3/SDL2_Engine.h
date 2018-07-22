///////////////////////////////
//	this class is a Engin in SDL2.start of the program from here
//	程序从这里开始
//	引擎类
//	2018年6月23日 23:50:52
//	by	水华宝箱

#ifndef _SDL2_ENGINE_H_BOX
#define _SDL2_ENGINE_H_BOX
#include <SDL2/SDL.h>
#include <SDL2_SceneManager.h>
#include <SDL2_Package.h>
#include <SDL2_Renderer.h>
#include <SDL2_MainWindow.h>
#include <SDL2_FontSystem.h>


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
		*	\brief 启动引擎
		*
		*/
		void StartEngine();

		/*
		*	\brief 获取场景管理器实例
		*
		*	\return	返回场景管理器实例
		*/
		SDL2_SceneManager *getSceneManager(){ return mSceneManager;}

		/*
		*	\brief	得到渲染器实例
		*	
		*	\return	渲染器实例
		*/
		SDL_Renderer *getRenderer();
	private :
		SDL2_SceneManager *mSceneManager;
		static SDL2_Engine *mEngine;
		
	private:
		SDL2_Engine();

	};
}
#endif	//	!_SDL2_ENGINE_H_BOX