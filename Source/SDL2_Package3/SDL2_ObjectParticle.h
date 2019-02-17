///////////////////////////////
//	this class is a Object in SDL2.
//	从一个条线开始发射粒子，一般用来下雨什么的
//	《粒子发射器线类》
//	2019年2月17日 02:53:29
//	by	水华宝箱

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
		Math::vec2								m_Point;			//	粒子的位置
		float									m_Life;				//	粒子的生命
		float									m_Speed;			//	粒子的速度
		float									m_SpeedDamping;		//	粒子的速度衰减
		Math::vec2								m_Size;				//	粒子的尺寸
		Math::vec2								m_Direction;		//	粒子运动方向
	protected:
		SDL2_ObjectParticle();
	};

}
#endif //!_SDL2_OBJECT_PARTICLE_H_BOX_