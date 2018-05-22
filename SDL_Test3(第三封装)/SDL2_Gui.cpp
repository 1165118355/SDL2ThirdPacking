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

int WaterBox::SDL2_Gui::addComponent(SDL2_Component *component)
{
	static int count=0;
	mComponents.insert(std::pair<int, SDL2_Component *>(count++, component));
	return 0;
}
