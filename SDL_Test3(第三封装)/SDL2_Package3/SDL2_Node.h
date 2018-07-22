#pragma once
#include <SDL2_Math.h>

namespace WaterBox
{
	class SDL2_Node
	{
	public:
		/// brief	����λ��
		virtual void setPosition(Math::vec2 position)=0;
		virtual Math::vec2 getPosition()=0;
		
		///	brief	���óߴ�
		virtual void setSize(Math::vec2 size) = 0;
		virtual Math::vec2 getSize() = 0;

		///	brief	������һ��
		virtual ~SDL2_Node();
	protected:
		Math::vec2 m_Position;
		Math::vec2 m_Size;

		SDL2_Node();
	};
}
