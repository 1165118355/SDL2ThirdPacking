///////////////////////////////
//	this class is a Object in SDL2.
//	��һ�����η������ӣ�����һ����Χ�ڲ�ͣ�������������
//	�����ӷ����������ࡷ
//	2019��2��17�� 02:53:29
//	by	ˮ������

#ifndef _SDL2_OBJECT_PARTICLE_EMITTER_RECT_H_BOX_
#define _SDL2_OBJECT_PARTICLE_EMITTER_RECT_H_BOX_

#include <SDL2_ObjectParticleEmitter.h>

namespace WaterBox
{
	class SDL2_ObjectParticleEmitterRect :public SDL2_ObjectParticleEmitter
	{
	public:
		///	\brief		���� ҮҮҮ
		static SDL2_ObjectParticleEmitterRect *create();
		~SDL2_ObjectParticleEmitterRect();

		///	\brief	�������ӵĺ�����װ
		virtual void generateParticle();
	protected:
		SDL2_ObjectParticleEmitterRect();
	};
}
#endif //!_SDL2_OBJECT_PARTICLE_EMITTER_RECT_H_BOX_
