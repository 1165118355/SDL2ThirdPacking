#ifndef _SDL2_GUI_H_BOX
#define _SDL2_GUI_H_BOX
#include <map>
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

		//	单例模式获取Gui
		static SDL2_Gui *get();

		//	添加组件
		int addComponent(SDL2_Component *component);

		//	清理Gui所有的组件
		void clear();

		//	Gui刷新一次
		void refresh();

		int getFps() { return m_Fps; }
		int setFps(int fps) { m_Fps = fps; }
	private:
		SDL2_Gui();
		static int update(void *ptr);
	private:
		static SDL2_Gui *m_gui;
		std::map<int, SDL2_Component *> m_Components;
		int m_Fps;

	};
}
#endif	//	!_SDL2_GUI_H