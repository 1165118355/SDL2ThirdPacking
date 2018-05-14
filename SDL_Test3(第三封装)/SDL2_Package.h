#ifndef _SDL2_PACKAGE_BOX
#define _SDL2_PACKAGE_BOX

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
#endif// !_SDL2_PACKAGE_BOX