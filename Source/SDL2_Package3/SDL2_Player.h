///////////////////////////////
//	this class is a Player in SDL2.
//	�������������ʾ������
//	������ࡷ
//	2018��8��13�� 20:10:15
//	by	ˮ������

#ifndef _SDL2_PLAYER_H_BOX
#define _SDL2_PLAYER_H_BOX

#include <SDL2_Node.h>

namespace WaterBox
{
	class SDL2_Player :public SDL2_Node
	{
	public:
		static SDL2_Player *create();

		///	\brief	����������Ŀ��ӷ�Χ
		void setFov(Math::vec2 fov);
		Math::vec2 getFov();

		///	\brief	��������볡���ľ���
		void setDistance(float distance);
		float getDistance();
	private:
		SDL2_Player();
	private:
		Math::vec2 m_Fov;		//	������ӷ�Χ
		float m_Distance;			//	��������ľ���
	};
}
#endif //!_SDL2_PLAYER_H_BOX