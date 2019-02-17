///////////////////////////////
//	this class is a Object in SDL2.
//	他来管理发射粒子的方式等
//	《粒子发射器类》
//	2019年2月17日 02:53:29
//	by	水华宝箱

#ifndef _SDL2_OBJECT_PARTICLE_EMITTER_H_BOX_
#define _SDL2_OBJECT_PARTICLE_EMITTER_H_BOX_

#include <vector>
#include <SDL2_Math.h>

namespace WaterBox
{
	class SDL2_ObjectParticleSystem;
	class SDL2_ObjectParticle;
	class SDL2_Material;
	class SDL2_ObjectParticleEmitter
	{
	public :
		enum EmitterType
		{
			EMITTER_POINT,
			EMITTER_LINE,
			EMITTER_RECT
		};
	public:
		friend SDL2_ObjectParticleSystem;
		~SDL2_ObjectParticleEmitter();

		///	\brief	更新走起
		virtual void update();

		///	\brief	渲染走走起
		virtual void show();

		///	\brief	获取发射器的类型
		EmitterType getType();

		///	\brief	设置位置
		virtual void setPosition(Math::vec2 pos);

		///	\brief	设置重力
		virtual void setGravity(Math::vec2 gravity);
		Math::vec2 getGravity();

		///	\brief	设置发射粒子的角度
		virtual void setEmitAngle(float angle);
		float getEmitAngle();

		///	\brief	设置发射粒子的角度范围
		virtual void setEmitAngleSpread(float spread);
		float getEmitAngleSpread();

		///	\brief	设置粒子的速度
		virtual void setSpeed(float speed);
		float getSpeed();

		///	\brief	设置粒子速度的范围 speed  = speed+spread ~ speed-spread
		virtual void setSpeedSpread(float spread);
		float getSpeedSpread();

		///	\brief	设置粒子的生命值
		virtual void setLife(float life);
		float getLife();

		///	\brief	设置粒子生命值范围
		virtual void setLifeSpread(float spread);
		float getLifeSpread();

		///	\brief	设置粒子的每秒生产数
		virtual void setProduction(float production);
		float getProduction();

		///	\brief	设置粒子的尺寸
		void setSize(Math::vec2 size);
		Math::vec2 getSize();

		///	\brief	设置粒子的尺寸范围
		void setSizeSpread(float spread);
		float getSizeSpread();

		///	\brief	设置粒子的尺寸衰减
		void setSizeDamping(float damping);
		float getSizeDamping();

		void setIndensity(float indensity);
		float getIndensity();

		void setMaterial(SDL2_Material *material);

	protected:
		SDL2_ObjectParticleEmitter();

		///	\brief	生成粒子的函数封装
		virtual void generateParticle();
	protected:
		Math::vec2		m_Position;
		Math::vec2		m_Gravity;						//	重力
		Math::vec2		m_EmitDirection;				//	发射器方向
		float			m_EmitDirectionAngle;			//	发射器方向的角度
		float			m_EmitDirectionAngleSpread;		//	发射器方向的角度范围
		float			m_EmitSpeed;					//	发射的粒子速度
		float			m_EmitSpeedSpread;				//	发射的粒子速度浮动范围
		float			m_EmitSpeedDamping;				//	发射的粒子速度衰减
		float			m_Life;							//	剩余生命值
		float			m_LifeSpread;					//	生命的浮动范围
		float			m_Production;					//	每秒粒子的产量
		float			m_Indensity;					//	密度
		Math::vec2		m_Size;							//	尺寸
		float			m_SizeDamping;					//	尺寸衰减

		EmitterType		m_EmitterType;					//	发射器类型

		std::vector<SDL2_ObjectParticle *> m_Particles;		//	存放粒子
		SDL2_Material *m_Material;
	};
}
#endif	//	!_SDL2_OBJECT_PARTICLE_EMITTER_H_BOX_

