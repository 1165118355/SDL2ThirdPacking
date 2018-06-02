#ifndef _SDL2_GUI_H_BOX
#define _SDL2_GUI_H_BOX
#include <map>
#include <SDL2_Component.h>
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
	private:
		SDL2_Gui();
		static int update(void *ptr);
	private:
		static SDL2_Gui *m_gui;
		std::map<int, SDL2_Component *> m_Components;

	};
}
#endif	//	!_SDL2_GUI_H