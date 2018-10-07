///////////////////////////////
//	this class is a Object in SDL2.
//	һ������һ����˵��һ�����ڵ����壬ӵ�в��ʵ�
//	�������ࡷ
//	2018��8��13�� 20:11:05
//	by	ˮ������

#ifndef _SDL2_OBJECT_H_BOX
#define _SDL2_OBJECT_H_BOX

#include <SDL2_Math.h>
#include <SDL2_Node.h>
#include <SDL2_Material.h>
#include <vector>
namespace WaterBox
{
	class SDL2_Object :public SDL2_Node
	{
	public:
		virtual ~SDL2_Object();
		static SDL2_Object *create(SDL2_Xml *xml);

		///	brief	��ȡ&���ö�������Ļ�е�λ��
		virtual void setPositionShow(Math::vec2 position);
		virtual Math::vec2 getPositionShow();

		///	\brief	���óߴ����
		void setScale(float scale);
		float getScale();

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		///	brief	��ʾ�������
		virtual void show();

		///	brief	�������������߼�
		virtual void update();

		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	����Object�����һ��Xml��ʽ
		virtual SDL2_Xml *saveToXml();
		
		///	brief	��ȡ����
		std::vector<SDL2_Material *> getMaterials();
	protected:
		SDL2_Object();
	protected:
		Math::vec2 m_PositionShow;							//	�ñ���ָʾ������ʾ����Ļ�е�λ��
		float m_Scale;										//	�ñ���ָʾ������ʾ����Ļ�еĳߴ�
		SDL2_Xml *m_Xml;
		std::vector<SDL2_Material **> m_Materials;
	};
}
#endif	//	!_SDL2_OBJECT_H_BOX