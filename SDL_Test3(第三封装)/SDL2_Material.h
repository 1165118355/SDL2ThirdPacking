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
		enum MaterialType
		{
			TYPE_PARENT = 0,
			TYPE_PICTURE,
			TYPE_ANIMAL
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
		WaterBox::Math::vec2 m_Position;
		WaterBox::Math::vec2 m_Size;
		MaterialType m_Type;
	private:

	};
}
#endif	//	!_SDL2_MATERIAL_H_BOX