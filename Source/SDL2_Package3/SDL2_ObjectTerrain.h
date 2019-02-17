///////////////////////////////
//	this class is a Object in SDL2.
//	一个对象，一般来说是一个存在的物体，拥有材质等
//	《地形类》
//	2018年10月13日 04:22:56
//	by	水华宝箱

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

		///	\brief	添加一个地形层
		void addLayer(SDL2_ObjectTerrainLayer *layer);

	private:
		SDL2_ObjectTerrain();
	private:
		std::vector<SDL2_ObjectTerrainLayer *> m_Layer;
	};
}
#endif//!_SDL2_OBJECTTERRAIN_H_BOX

