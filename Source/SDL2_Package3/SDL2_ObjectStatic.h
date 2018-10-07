#ifndef _SDL2_OBJECTSTATIC_H_BOX
#define _SDL2_OBJECTSTATIC_H_BOX

#include <SDL2_Object.h>

namespace WaterBox
{

	class SDL2_ObjectStatic :public SDL2_Object
	{
	public:
		static SDL2_ObjectStatic *create(SDL2_Material *material);
		static SDL2_ObjectStatic *create(SDL2_Xml *xml);

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

		///	\brief	设置静态图像材质
		bool setMaterialImage(SDL2_Material *material);
		SDL2_Material *getMaterialImage();
	protected:
		SDL2_ObjectStatic();
		~SDL2_ObjectStatic();
	protected:
		SDL2_Material *m_MaterialImage;
	};
}

#endif // !_SDL2_OBJECTSTATIC_H_BOX
