///////////////////////////////
//	this class is a Object in SDL2.
//	一个对象，一般来说是一个存在的物体，拥有材质等
//	《对象类》
//	2018年8月13日 20:11:05
//	by	水华宝箱

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

		///	brief	获取&设置对象在屏幕中的位置
		virtual void setPositionShow(Math::vec2 position);
		virtual Math::vec2 getPositionShow();

		///	\brief	设置尺寸比例
		void setScale(float scale);
		float getScale();

		///	\brief	获取重叠的掩码
		void setOverlapMask(int mask);
		int getOverlapMask();

		///	\brief	材质的位置校正，保证材质显示在物体上的正确位置上，类似3d里面的UV一样
		virtual void materialModification();

		///	brief	显示这个对象
		virtual void show();

		///	brief	更新这个对象的逻辑
		virtual void update();

		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	将该Object保存成一个Xml格式
		virtual SDL2_Xml *saveToXml();
		
		///	brief	获取材质
		std::vector<SDL2_Material *> getMaterials();
	protected:
		SDL2_Object();
	protected:
		Math::vec2 m_PositionShow;							//	该变量指示物体显示在屏幕中的位置
		float m_Scale;										//	该变量指示物体显示在屏幕中的尺寸
		SDL2_Xml *m_Xml;
		std::vector<SDL2_Material **> m_Materials;
		int m_OverlapMask;									//	存储重叠掩码
	};
}
#endif	//	!_SDL2_OBJECT_H_BOX