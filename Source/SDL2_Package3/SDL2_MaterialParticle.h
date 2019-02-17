///////////////////////////////
//	this class is a Material in SDL2. Save the Material use the class please.
//	材质的总类，一般用这个类来进行材质的存储
//	《材质粒子类》
//	2019年2月16日 19:23:17
//	by	水华宝箱

#ifndef _SDL2_MATERIAL_PARTICLE_H_BOX
#define _SDL2_MATERIAL_PARTICLE_H_BOX

namespace WaterBox
{
	class SDL2_MaterialParticle
	{
	public:
		///	\brief	创建
		static SDL2_MaterialParticle *create();
		~SDL2_MaterialParticle();


		SDL2_MaterialParticle();
	};
}


#endif //!_SDL2_MATERIAL_PARTICLE_H_BOX