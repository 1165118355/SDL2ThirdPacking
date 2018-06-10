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
		//	设置组件的位置
		virtual void setPosition(Math::vec2 &position);
		virtual Math::vec2 getPosition();

		//	设置组件的尺寸
		virtual void setSize(Math::vec2 &size);
		virtual Math::vec2 getSize();

		//	获取组件类型
		virtual Type getType() { return type; }
		virtual int show()=0;

		//	组件更新（包括事件检测，逻辑判断）
		virtual void update() {}
	protected:
		Type type;
		Math::vec2 m_Position;
		Math::vec2 m_Size;
	private:
	};
}

#endif// !_SDL2_COMPONENT_BOX