///////////////////////////////
//	this class is a Node in SDL2.
//	��ʾһ�����壬���Ǻܶ�����Ļ���
//	���ڵ��ࡷ
//	2018��8��13�� 20:08:34
//	by	ˮ������
#ifndef _SDL2_NODE_H_BOX
#define _SDL2_NODE_H_BOX

#include <SDL2_Math.h>

namespace WaterBox
{
	class SDL2_Node
	{
	public:
		/// brief	����λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();
		
		///	brief	���óߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		virtual int getId();

		///	brief	������һ��
		virtual ~SDL2_Node();
	protected:
		SDL2_Node();
	protected:
		Math::vec2 m_Position;
		Math::vec2 m_Size;
		int m_Id;
	};
}

#endif // !_SDL2_NODE_H_BOX