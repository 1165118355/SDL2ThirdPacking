///////////////////////////////
//	this class is a window in SDL2.
//	窗口的创建等，预计之后会改进这个类
//	《窗口类》
//	2018年6月24日 00:19:12
//	by	水华宝箱

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
		SDL2_Window(std::string name="window", int x=100, int y=100, int w=400, int h=400, int mode=0);
		SDL_Window *getWindow() { return win; }
	private:
		SDL_Window *win;
	};
}
#endif	//`!_SDL2_WINDOW_H_BOX