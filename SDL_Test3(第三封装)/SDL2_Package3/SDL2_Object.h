#ifndef _SDL2_OBJECT_H_BOX
#define _SDL2_OBJECT_H_BOX
#include <SDL2_Math.h>
namespace WaterBox
{
	class SDL2_Object
	{
	public:
		void setPosition(Math::vec2 position);
		Math::vec2 getPosition();

		void setSize(Math::vec2 size);
		Math::vec2 getSize();
		
	private:
		SDL2_Object() {}
		Math::vec2 m_Position;
	};
}
#endif	//	!_SDL2_OBJECT_H_BOX