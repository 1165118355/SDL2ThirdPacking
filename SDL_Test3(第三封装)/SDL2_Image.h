#ifndef _SDL2_IMAGE_H_BOX
#define _SDL2_IMAGE_H_BOX

#include <SDL2_Component.h>
#include <SDL2_Material.h>
#include <SDL2/SDL.h>

namespace WaterBox
{
	class SDL2_Image:public SDL2_Component
	{
	public:
		SDL2_Image();
		SDL2_Image(std::string path);

		//	œ‘ æUI
		virtual int show();
	protected:

	private:
		SDL2_Material *m_Material;
	};
}

#endif// !_SDL2_IMAGE_H_BOX