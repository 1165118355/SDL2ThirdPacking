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

		//	设置位置
		void setPosition(Math::vec2 position);
		Math::vec2 getPosition();

		//	设置尺寸
		void setSize(Math::vec2 size);
		Math::vec2 getSize();

		//	显示
		virtual void show() {}

		virtual MaterialType getType();

	protected:
		SDL2_Material();
		Math::vec2 m_Position;
		Math::vec2 m_Size;
		MaterialType m_Type;
	private:

	};
}
#endif	//	!_SDL2_MATERIAL_H_BOX