#ifndef _SDL2_OBJECT_H_BOX
#define _SDL2_OBJECT_H_BOX
#include <SDL2_Math.h>
namespace WaterBox
{
	class SDL2_Object
	{
	public:
		SDL2_Object();
		Math::vec2 getPosition() { return mPosition; }
		void setPosition(Math::vec2 position) { mPosition = position; }
	private:
		Math::vec2 mPosition;
	};
}
#endif	//	!_SDL2_OBJECT_H_BOX