///////////////////////////////
//	this class is a Object in SDL2.
//	�������������ӷ���Ĺ���ȵ�
//	������ϵͳ�ࡷ
//	2019��2��17�� 02:51:48
//	by	ˮ������

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

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		///	brief	��ʾ�������
		virtual void show();

		///	brief	�������������߼�
		virtual void update();

		///	\brief	����Object�����һ��Xml��ʽ
		virtual SDL2_Xml *saveToXml();

		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	���ò���
		void setMaterialParticle(const char *material);
		void setMaterialParticle(SDL2_Material *material);

		///	\brief	���÷�����������
		void setEmitterType(SDL2_ObjectParticleEmitter::EmitterType type);
		SDL2_ObjectParticleEmitter::EmitterType getEmitterType();

		///	\brief	�õ���������ʵ��
		SDL2_ObjectParticleEmitter *getEmitter();

	protected:
		SDL2_ObjectParticleSystem();
	private:
		SDL2_Material					*m_Material;	//	���ʿ�
		SDL2_ObjectParticleEmitter		*m_Emitter;		//	������
	};
}
#endif //!_SDL2_OBJECT_PARTICLE_SYSTEM_H_BOX_
