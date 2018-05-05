#pragma once
#include <SDL2_Component.h>
namespace WaterBox
{
	class SDL2_Gui
	{
	public :
		static SDL2_Gui *get();
	private:

		SDL2_Gui() {}
		static SDL2_Gui *mgui;

	};
}