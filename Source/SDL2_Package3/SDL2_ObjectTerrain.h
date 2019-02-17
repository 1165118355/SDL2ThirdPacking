///////////////////////////////
//	this class is a Object in SDL2.
//	һ������һ����˵��һ�����ڵ����壬ӵ�в��ʵ�
//	�������ࡷ
//	2018��10��13�� 04:22:56
//	by	ˮ������

#ifndef _SDL2_OBJECTTERRAIN_H_BOX
#define _SDL2_OBJECTTERRAIN_H_BOX

#include <SDL2_Object.h>
#include <SDL2_Xml.h>
#include <SDL2_ObjectTerrainLayer.h>

namespace WaterBox
{
	class SDL2_ObjectTerrain : public SDL2_Object
	{
	public:
		~SDL2_ObjectTerrain();
		static SDL2_ObjectTerrain *create();

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

		///	\brief	���һ�����β�
		void addLayer(SDL2_ObjectTerrainLayer *layer);

	private:
		SDL2_ObjectTerrain();
	private:
		std::vector<SDL2_ObjectTerrainLayer *> m_Layer;
	};
}
#endif//!_SDL2_OBJECTTERRAIN_H_BOX

