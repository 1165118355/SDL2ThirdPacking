#ifndef _SDL2_OBJECT_H_BOX
#define _SDL2_OBJECT_H_BOX
#include <SDL2_Math.h>
#include <SDL2_Node.h>
namespace WaterBox
{
	class SDL2_Object :public SDL2_Node
	{
	public:   
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();
		
	protected:
		SDL2_Object() {}
	};
}
#endif	//	!_SDL2_OBJECT_H_BOX