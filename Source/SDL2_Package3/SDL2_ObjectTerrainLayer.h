///////////////////////////////
//	this class is a Object in SDL2.
//	一个对象，一般来说是一个存在的物体，拥有材质等
//	《地形层类》
//	2018年10月13日 04:22:56
//	by	水华宝箱

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

		///	\brief	设置行列数
		void setNumRowColumn(Math::vec2 number);

		///	\brief	显示
		void show();

	private:
		SDL2_ObjectTerrainLayer();
	private:
		std::vector<std::vector<int>> m_Map;
		std::map<int, std::string> m_Maping;			//	映射，地图的值对应的材质名称
	};
}

#endif//!_SDL2_OBJECTTERRAINLAYER_H_BOX
