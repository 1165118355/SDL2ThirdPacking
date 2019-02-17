///////////////////////////////
//	this class is a Object in SDL2.
//	�������������ӵķ�ʽ��
//	�����ӷ������ࡷ
//	2019��2��17�� 02:53:29
//	by	ˮ������

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

		///	\brief	��������
		virtual void update();

		///	\brief	��Ⱦ������
		virtual void show();

		///	\brief	��ȡ������������
		EmitterType getType();

		///	\brief	����λ��
		virtual void setPosition(Math::vec2 pos);

		///	\brief	��������
		virtual void setGravity(Math::vec2 gravity);
		Math::vec2 getGravity();

		///	\brief	���÷������ӵĽǶ�
		virtual void setEmitAngle(float angle);
		float getEmitAngle();

		///	\brief	���÷������ӵĽǶȷ�Χ
		virtual void setEmitAngleSpread(float spread);
		float getEmitAngleSpread();

		///	\brief	�������ӵ��ٶ�
		virtual void setSpeed(float speed);
		float getSpeed();

		///	\brief	���������ٶȵķ�Χ speed  = speed+spread ~ speed-spread
		virtual void setSpeedSpread(float spread);
		float getSpeedSpread();

		///	\brief	�������ӵ�����ֵ
		virtual void setLife(float life);
		float getLife();

		///	\brief	������������ֵ��Χ
		virtual void setLifeSpread(float spread);
		float getLifeSpread();

		///	\brief	�������ӵ�ÿ��������
		virtual void setProduction(float production);
		float getProduction();

		///	\brief	�������ӵĳߴ�
		void setSize(Math::vec2 size);
		Math::vec2 getSize();

		///	\brief	�������ӵĳߴ緶Χ
		void setSizeSpread(float spread);
		float getSizeSpread();

		///	\brief	�������ӵĳߴ�˥��
		void setSizeDamping(float damping);
		float getSizeDamping();

		void setIndensity(float indensity);
		float getIndensity();

		void setMaterial(SDL2_Material *material);

	protected:
		SDL2_ObjectParticleEmitter();

		///	\brief	�������ӵĺ�����װ
		virtual void generateParticle();
	protected:
		Math::vec2		m_Position;
		Math::vec2		m_Gravity;						//	����
		Math::vec2		m_EmitDirection;				//	����������
		float			m_EmitDirectionAngle;			//	����������ĽǶ�
		float			m_EmitDirectionAngleSpread;		//	����������ĽǶȷ�Χ
		float			m_EmitSpeed;					//	����������ٶ�
		float			m_EmitSpeedSpread;				//	����������ٶȸ�����Χ
		float			m_EmitSpeedDamping;				//	����������ٶ�˥��
		float			m_Life;							//	ʣ������ֵ
		float			m_LifeSpread;					//	�����ĸ�����Χ
		float			m_Production;					//	ÿ�����ӵĲ���
		float			m_Indensity;					//	�ܶ�
		Math::vec2		m_Size;							//	�ߴ�
		float			m_SizeDamping;					//	�ߴ�˥��

		EmitterType		m_EmitterType;					//	����������

		std::vector<SDL2_ObjectParticle *> m_Particles;		//	�������
		SDL2_Material *m_Material;
	};
}
#endif	//	!_SDL2_OBJECT_PARTICLE_EMITTER_H_BOX_

