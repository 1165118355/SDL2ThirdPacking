#ifndef _SDL2_IMAGE_H_BOX
#define _SDL2_IMAGE_H_BOX

#include <SDL2_Component.h>
#include <SDL2/SDL.h>

namespace WaterBox
{
	class SDL2_Image:public SDL2_Component
	{
	public:
		SDL2_Image();
		virtual int show();
	protected:

	private:
		SDL_Surface *sur;
		SDL_Texture *tex;
	};
}

#endif// !_SDL2_IMAGE_H_BOX