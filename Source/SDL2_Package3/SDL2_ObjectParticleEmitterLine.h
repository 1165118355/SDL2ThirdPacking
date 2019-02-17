///////////////////////////////
//	this class is a Object in SDL2.
//	从一个条线开始发射粒子，一般用来下雨什么的
//	《粒子发射器线类》
//	2019年2月17日 02:53:29
//	by	水华宝箱

#ifndef _SDL2_OBJECT_PARTICLE_EMITTER_LINE_H_BOX_
#define _SDL2_OBJECT_PARTICLE_EMITTER_LINE_H_BOX_

#include <SDL2_ObjectParticleEmitter.h>

namespace WaterBox
{
	class SDL2_ObjectParticleEmitterLine :public SDL2_ObjectParticleEmitter
	{
	public:
		///	\breif	创建
		static SDL2_ObjectParticleEmitterLine *create();
		~SDL2_ObjectParticleEmitterLine();

		///	\brief	生成粒子的函数封装
		virtual void generateParticle();
	protected:
		SDL2_ObjectParticleEmitterLine();
	};
}
#endif //	!_SDL2_OBJECT_PARTICLE_EMITTER_LINE_H_BOX_
