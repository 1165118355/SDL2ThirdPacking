///////////////////////////////
//	this class is a Object in SDL2.
//	��һ�����߿�ʼ�������ӣ�һ����������ʲô��
//	�����ӷ��������ࡷ
//	2019��2��17�� 02:53:29
//	by	ˮ������

#ifndef _SDL2_OBJECT_PARTICLE_H_BOX_
#define _SDL2_OBJECT_PARTICLE_H_BOX_
#include <SDL2_Math.h>

namespace WaterBox
{
	class SDL2_ObjectParticle
	{
	public:
		static SDL2_ObjectParticle * create();
		~SDL2_ObjectParticle();
	public:
		Math::vec2								m_Point;			//	���ӵ�λ��
		float									m_Life;				//	���ӵ�����
		float									m_Speed;			//	���ӵ��ٶ�
		float									m_SpeedDamping;		//	���ӵ��ٶ�˥��
		Math::vec2								m_Size;				//	���ӵĳߴ�
		Math::vec2								m_Direction;		//	�����˶�����
	protected:
		SDL2_ObjectParticle();
	};

}
#endif //!_SDL2_OBJECT_PARTICLE_H_BOX_