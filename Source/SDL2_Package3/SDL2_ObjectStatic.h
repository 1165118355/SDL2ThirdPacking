#ifndef _SDL2_OBJECTSTATIC_H_BOX
#define _SDL2_OBJECTSTATIC_H_BOX

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

#endif // !_SDL2_OBJECTSTATIC_H_BOX
