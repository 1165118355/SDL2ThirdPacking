///////////////////////////////
//	this class is a Object in SDL2.
//	从一个矩形发射粒子，会在一个范围内不停的随机生成粒子
//	《粒子发射器矩形类》
//	2019年2月17日 02:53:29
//	by	水华宝箱

#ifndef _SDL2_OBJECT_PARTICLE_EMITTER_RECT_H_BOX_
#define _SDL2_OBJECT_PARTICLE_EMITTER_RECT_H_BOX_

#include <SDL2_ObjectParticleEmitter.h>

namespace WaterBox
{
	class SDL2_ObjectParticleEmitterRect :public SDL2_ObjectParticleEmitter
	{
	public:
		///	\brief		创建 耶耶耶
		static SDL2_ObjectParticleEmitterRect *create();
		~SDL2_ObjectParticleEmitterRect();

		///	\brief	生成粒子的函数封装
		virtual void generateParticle();
	protected:
		SDL2_ObjectParticleEmitterRect();
	};
}
#endif //!_SDL2_OBJECT_PARTICLE_EMITTER_RECT_H_BOX_
