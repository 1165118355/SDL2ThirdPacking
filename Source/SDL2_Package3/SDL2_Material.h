///////////////////////////////
//	this class is a Material in SDL2. Save the Material use the class please.
//	材质的总类，一般用这个类来进行材质的存储
//	《材质类》
//	2018年6月23日 23:58:53
//	by	水华宝箱

#ifndef _SDL2_MATERIAL_H_BOX
#define _SDL2_MATERIAL_H_BOX

#include <string>
#include <SDl2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2_Math.h>
#include <SDL2_Xml.h>

namespace WaterBox
{
	class SDL2_Material
	{
	public :
		///	材质类型的枚举
		enum MaterialType
		{
			TYPE_PARENT = 0,	//	就是该类
			TYPE_PICTURE,		//	图片材质类
			TYPE_ANIMAL,		//	动画材质类
			TYPE_TEXT			//	文字材质类
		};
	public:
		static SDL2_Material *create();
		~SDL2_Material();

		///	brief	设置位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	设置尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	设置剪切w位置
		virtual void setCutPosition(Math::vec2 position);
		virtual Math::vec2 getCutPosition();

		///	brief	设置剪切尺寸
		virtual void setCutSize(Math::vec2 size);
		virtual Math::vec2 getCutSize();

		///	brief	设置材质的名称
		virtual void setName(std::string name);
		virtual std::string getName();

		///	\brief	设置材质的透明度
		virtual void setTransparent(int transparent);
		virtual int getTransparent();

		///	brief	恢复默认尺寸
		virtual void reSize();

		///	brief	显示
		virtual void show();

		///	\brief	保存材质成xml格式
		virtual SDL2_Xml *save();

		///	\brief	加载一个材质
		virtual int load(SDL2_Xml *materialXml);

		///	\brief	重新加载这个材质（一般用于多窗口渲染时用到）
		virtual void reload();

		///	\brief	获取材质的类型
		virtual MaterialType getType();

	protected:
		SDL2_Material();
		void setDefaultSize(Math::vec2 size);
	protected:
		MaterialType m_Type;
		SDL2_Xml *m_MaterialXml;
		std::string m_Name;
		Math::vec2 m_CutSize;
		Math::vec2 m_CutPosition;
		Math::vec2 m_Position;
		Math::vec2 m_Size;
		Math::vec2 m_DefaultSize;
	private:

	};
}
#endif	//	!_SDL2_MATERIAL_H_BOX