#include "SDL2_Package.h"

using namespace WaterBox;

int SDL2_Package::init()
{
	SDL_Window *win = SDL_CreateWindow("My_window", 0, 0, 500, 500, 0);
	return 1;
}

int SDL2_Package::update()
{
	return 0;
}

int SDL2_Package::shutdown()
{
	return 0;
}
