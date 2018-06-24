#include "SDL2_Window.h"

using namespace WaterBox;

WaterBox::SDL2_Window::SDL2_Window(std::string name, int x, int y, int w, int h, int mode)
{
	win = SDL_CreateWindow(name.c_str(), x, y, w, h, 0);
}