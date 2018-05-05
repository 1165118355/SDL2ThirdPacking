#include "SDL2_Gui.h"

using namespace WaterBox;

SDL2_Gui *SDL2_Gui::mgui = nullptr;

SDL2_Gui * WaterBox::SDL2_Gui::get()
{
	if (mgui == nullptr)
	{
		mgui = new SDL2_Gui();
	}
	return nullptr;
}
