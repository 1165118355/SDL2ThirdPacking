#ifndef _SDL2_ENGINE_H_BOX
#define _SDL2_ENGINE_H_BOX
#include <SDL2/SDL.h>
#include <SDL2_SceneManager.h>
#include <SDL2_Package.h>
#include <SDL2_Renderer.h>
#include <SDL2_Window.h>

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
		SDL2_Window *mWindow;
		SDL_Renderer *rend;
		
		static SDL2_Engine *mEngine;
		
	private:
		SDL2_Engine();

	};
}
#endif	//	!_SDL2_ENGINE_H_BOX