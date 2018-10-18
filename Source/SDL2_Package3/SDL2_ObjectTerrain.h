///////////////////////////////
//	this class is a Object in SDL2.
//	һ������һ����˵��һ�����ڵ����壬ӵ�в��ʵ�
//	�������ࡷ
//	2018��10��13�� 04:22:56
//	by	ˮ������

#ifndef _SDL2_OBJECTSTATIC_H_BOX
#define _SDL2_OBJECTSTATIC_H_BOX
#include <SDL2_Xml.h>

namespace WaterBox
{
	class SDL2_ObjectTerrain
	{
	public:
		~SDL2_ObjectTerrain();


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

	private:
		SDL2_ObjectTerrain();
	private:
	};
}
#endif//!_SDL2_OBJECTSTATIC_H_BOX

