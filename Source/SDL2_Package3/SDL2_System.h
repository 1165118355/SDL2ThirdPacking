///////////////////////////////
//	this class is a System in SDL2.
//	系统类，场景加载之前的运行的
//	《系统类》
//	2018年10月1日 13:48:00
//	by	水华宝箱

#ifndef _SDL2_SYSTEM_H_BOX
#define _SDL2_SYSTEM_H_BOX

#include <SDL2_SceneManager.h>

namespace WaterBox
{
	class SDL2_System
	{
	public:
		static SDL2_System *get();

		void init();

		void update();

		void render();

		void shutdown();


		/*
		*	\brief 获取场景管理器实例
		*
		*	\return	返回场景管理器实例
		*/
		SDL2_SceneManager *getSceneManager() { return m_SceneManager; }

	private:
		~SDL2_System();
		SDL2_System();
	private:
		static SDL2_System *m_Instance;
		SDL2_SceneManager *m_SceneManager;
		SDL2_Scene *m_NowScene;
		SDL_Event *m_Event;								//	事件管理器（这个将会传给每个组件，每种组件内部去实现自己的逻辑）
	};
}

#endif // !_SDL2_SYSTEM_H_BOX