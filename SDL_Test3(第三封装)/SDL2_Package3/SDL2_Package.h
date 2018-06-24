///////////////////////////////
//	this class is a Package in SDL2.some small tools
//	一些零散的工具集中在这里
//	《集中包类》
//	2018年6月23日 23:58:53
//	by	水华宝箱

#ifndef _SDL2_PACKAGE_H_BOX
#define _SDL2_PACKAGE_H_BOX

/*
将这个类继承来使用SDL封装程序
*/
#include <SDL2/SDL.h>
#include <SDL2_Renderer.h>
#include <SDL2_Gui.h>
namespace WaterBox
{
	class SDL2_Package
	{
	public:
		int init();
		int update();
		int shutdown();
	protected:

	private:
		SDL2_Package();
		SDL_Window *mwin;
	};
}
#endif// !_SDL2_PACKAGE_H_BOX