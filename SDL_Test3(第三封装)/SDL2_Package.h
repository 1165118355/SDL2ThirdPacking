#ifndef _SDL2_PACKAGE_H_BOX
#define _SDL2_PACKAGE_H_BOX

/*
�������̳���ʹ��SDL��װ����
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