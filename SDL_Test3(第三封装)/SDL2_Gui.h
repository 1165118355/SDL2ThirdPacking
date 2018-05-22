#ifndef _SDL2_GUI_H_BOX
#define _SDL2_GUI_H_BOX
#include <SDL2_Component.h>
#include <map>
namespace WaterBox
{
	class SDL2_Gui
	{
	public :
		static SDL2_Gui *get();
		int addComponent(SDL2_Component *component);
	private:
		std::map<int, SDL2_Component *> mComponents;

		SDL2_Gui() {}
		static SDL2_Gui *mgui;

	};
}
#endif	//	!_SDL2_GUI_H