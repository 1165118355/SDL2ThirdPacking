#ifndef _SDL2_GUI_H_BOX
#define _SDL2_GUI_H_BOX
#include <map>
#include <SDL2_Component.h>
namespace WaterBox
{
	class SDL2_Gui
	{
	public :

		//	����ģʽ��ȡGui
		static SDL2_Gui *get();

		//	������
		int addComponent(SDL2_Component *component);

		//	����Gui���е����
		void clear();

		//	Guiˢ��һ��
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