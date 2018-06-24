///////////////////////////////
//	this class is a Gui in SDL2.manage the UI
//	用来管理UI等
//	《GUI类》
//	2018年6月23日 23:58:53
//	by	水华宝箱

#ifndef _SDL2_GUI_H_BOX
#define _SDL2_GUI_H_BOX
#include <map>
#include <SDL2/SDL.h>
#include <SDL2_Component.h>

/*
帧数限制的方案还有问题需要修改）（对于帧数低于限制的时候可能会造成卡顿）
图像闪烁，可能是多线程调用的问题（renderClear后进入另一个线程，造成短暂黑屏），考虑rend单独开个线程，或是
*/

namespace WaterBox
{
	class SDL2_Gui
	{
	public :

		///	brief	单例模式获取Gui
		static SDL2_Gui *get();

		///	brief	添加组件
		int addComponent(SDL2_Component *component);

		///	brief	清理Gui所有的组件
		void clear();

		///	brief	Gui刷新一次
		void refresh();

		///	brief	更新函数
		static int update(void *ptr);
	private:
		SDL2_Gui();
	private:
		static SDL2_Gui *m_gui;
		std::map<int, SDL2_Component *> m_Components;	//	组件管理结构使用map来管理
		SDL_Event *event;								//	事件管理器（这个将会传给每个组件，每种组件内部去实现自己的逻辑）

	};
}
#endif	//	!_SDL2_GUI_H