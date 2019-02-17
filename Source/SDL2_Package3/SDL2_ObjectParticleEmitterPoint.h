///////////////////////////////
//	this class is a Object in SDL2.
//	��һ���㿪ʼ���ⷢ�����ӵķ�����
//	�����ӷ����������ࡷ
//	2019��2��17�� 02:53:29
//	by	ˮ������

#ifndef _SDL2_OBJECT_PARTICLE_EMITTER_POINT_H_BOX_
#define _SDL2_OBJECT_PARTICLE_EMITTER_POINT_H_BOX_

#include <SDL2_ObjectParticleEmitter.h>

namespace WaterBox
{
	class SDL2_ObjectParticleEmitterPoint :public SDL2_ObjectParticleEmitter
	{
	public:
		static SDL2_ObjectParticleEmitterPoint *create();
		~SDL2_ObjectParticleEmitterPoint();

	protected:
		SDL2_ObjectParticleEmitterPoint();

		///	\brief	�������ӵĺ�����װ
		virtual void generateParticle();
	private:
		Math::vec2		m_Point;						//	����㣨������㷢�����ӣ�
	};
}
#endif // !_SDL2_OBJECT_PARTICLE_EMITTER_POINT_H_BOX_

