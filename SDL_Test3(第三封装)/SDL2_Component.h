#ifndef _SDL2_COMPONENT_H_BOX
#define _SDL2_COMPONENT_H_BOX

/*
组件的基类
*/

#include <SDL2_Math.h>
namespace WaterBox
{
	class SDL2_Component
	{
	public :
		enum Type
		{
			COMPONENT_BUTTON=0	,
			COMPONENT_IMAGE		,
			COMPONENT_WINDOW	,

		};
	public :

		virtual void setPosition(Math::vec2 &position);
		virtual void setSize(Math::vec2 &size);
		virtual Math::vec2 getPosition();
		virtual Math::vec2 getSize();
		virtual Type getType() { return type; }
	protected:
		virtual int show()=0;
		Type type;
	private:
		Math::vec2 mposition;
		Math::vec2 msize;
	};
}

#endif// !_SDL2_COMPONENT_BOX