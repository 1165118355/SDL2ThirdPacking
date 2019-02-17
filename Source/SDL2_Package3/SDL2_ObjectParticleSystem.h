///////////////////////////////
//	this class is a Object in SDL2.
//	由他来进行粒子发射的管理等等
//	《粒子系统类》
//	2019年2月17日 02:51:48
//	by	水华宝箱

#ifndef _SDL2_OBJECT_PARTICLE_SYSTEM_H_BOX_
#define _SDL2_OBJECT_PARTICLE_SYSTEM_H_BOX_
#include <SDL2_Object.h>
#include <SDL2_ObjectParticleEmitter.h>

namespace WaterBox
{
	class SDL2_Material;
	class SDL2_ObjectParticleSystem : public SDL2_Object
	{
	public:
		static SDL2_ObjectParticleSystem *create();
		~SDL2_ObjectParticleSystem();

		///	\brief	材质的位置校正，保证材质显示在物体上的正确位置上，类似3d里面的UV一样
		virtual void materialModification();

		///	brief	显示这个对象
		virtual void show();

		///	brief	更新这个对象的逻辑
		virtual void update();

		///	\brief	将该Object保存成一个Xml格式
		virtual SDL2_Xml *saveToXml();

		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	设置材质
		void setMaterialParticle(const char *material);
		void setMaterialParticle(SDL2_Material *material);

		///	\brief	设置发射器的类型
		void setEmitterType(SDL2_ObjectParticleEmitter::EmitterType type);
		SDL2_ObjectParticleEmitter::EmitterType getEmitterType();

		///	\brief	拿到发射器的实例
		SDL2_ObjectParticleEmitter *getEmitter();

	protected:
		SDL2_ObjectParticleSystem();
	private:
		SDL2_Material					*m_Material;	//	材质咯
		SDL2_ObjectParticleEmitter		*m_Emitter;		//	发射器
	};
}
#endif //!_SDL2_OBJECT_PARTICLE_SYSTEM_H_BOX_
