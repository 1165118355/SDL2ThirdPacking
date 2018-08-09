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
		///	brief	获取位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	获取尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	显示这个对象
		virtual void show();
		
		///	brief	获取材质
		std::vector<SDL2_Material *> getMaterials();
	protected:
		SDL2_Object() {}
		std::vector<SDL2_Material **> m_Materials;
	};
}
#endif	//	!_SDL2_OBJECT_H_BOX