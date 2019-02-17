///////////////////////////////
//	this class is a Object in SDL2.
//	��һ�����߿�ʼ�������ӣ�һ����������ʲô��
//	�����ӷ��������ࡷ
//	2019��2��17�� 02:53:29
//	by	ˮ������

#ifndef _SDL2_OBJECT_PARTICLE_EMITTER_LINE_H_BOX_
#define _SDL2_OBJECT_PARTICLE_EMITTER_LINE_H_BOX_

#include <SDL2_ObjectParticleEmitter.h>

namespace WaterBox
{
	class SDL2_ObjectParticleEmitterLine :public SDL2_ObjectParticleEmitter
	{
	public:
		///	\breif	����
		static SDL2_ObjectParticleEmitterLine *create();
		~SDL2_ObjectParticleEmitterLine();

		///	\brief	�������ӵĺ�����װ
		virtual void generateParticle();
	protected:
		SDL2_ObjectParticleEmitterLine();
	};
}
#endif //	!_SDL2_OBJECT_PARTICLE_EMITTER_LINE_H_BOX_
