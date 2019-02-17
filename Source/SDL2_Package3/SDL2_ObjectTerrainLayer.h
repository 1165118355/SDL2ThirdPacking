///////////////////////////////
//	this class is a Object in SDL2.
//	һ������һ����˵��һ�����ڵ����壬ӵ�в��ʵ�
//	�����β��ࡷ
//	2018��10��13�� 04:22:56
//	by	ˮ������

#ifndef _SDL2_OBJECTTERRAINLAYER_H_BOX
#define _SDL2_OBJECTTERRAINLAYER_H_BOX

#include<SDL2_Object.h>

namespace WaterBox
{
	class SDL2_ObjectTerrainLayer : SDL2_Object
	{
	public:
		///	\brief	create a layer
		static SDL2_ObjectTerrainLayer *create(Math::vec2 number);
		~SDL2_ObjectTerrainLayer();

		///	\brief	����������
		void setNumRowColumn(Math::vec2 number);

		///	\brief	��ʾ
		void show();

	private:
		SDL2_ObjectTerrainLayer();
	private:
		std::vector<std::vector<int>> m_Map;
		std::map<int, std::string> m_Maping;			//	ӳ�䣬��ͼ��ֵ��Ӧ�Ĳ�������
	};
}

#endif//!_SDL2_OBJECTTERRAINLAYER_H_BOX
