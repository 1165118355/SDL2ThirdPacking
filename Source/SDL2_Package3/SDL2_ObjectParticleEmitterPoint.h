///////////////////////////////
//	this class is a Object in SDL2.
//	从一个点开始向外发射粒子的发射器
//	《粒子发射器单点类》
//	2019年2月17日 02:53:29
//	by	水华宝箱

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

		///	\brief	生成粒子的函数封装
		virtual void generateParticle();
	private:
		Math::vec2		m_Point;						//	发射点（从这个点发射粒子）
	};
}
#endif // !_SDL2_OBJECT_PARTICLE_EMITTER_POINT_H_BOX_

