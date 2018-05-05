#include "SDL2_Gui.h"

using namespace WaterBox;

SDL2_Gui *SDL2_Gui::mgui = NULL;

SDL2_Gui * WaterBox::SDL2_Gui::get()
{
	if (mgui == NULL)
	{
		mgui = new SDL2_Gui();
	}
	return nullptr;
}
