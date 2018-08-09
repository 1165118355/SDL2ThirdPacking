#pragma once
#include <SDL2_Object.h>

namespace WaterBox
{

	class SDL2_ObjectStatic :public SDL2_Object
	{
	public:
		static SDL2_ObjectStatic *create();

		
	protected:
		SDL2_ObjectStatic();
		~SDL2_ObjectStatic();
	protected:
		SDL2_Material *m_MaterialImage;
	};

}