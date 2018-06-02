#ifndef _SDL2_WINDOW_H_BOX
#define _SDL2_WINDOW_H_BOX
#include <SDl2/SDL.h>
#include <vector>
#include <string>

namespace WaterBox
{
	class SDL2_Window
	{
	public:
		SDL2_Window(std::string name="window", int x=0, int y=0, int w=400, int h=400, int mode=0);
		SDL_Window *getWindow() { return win; }
	private:
		SDL_Window *win;
	};
}
#endif	//`!_SDL2_WINDOW_H_BOX