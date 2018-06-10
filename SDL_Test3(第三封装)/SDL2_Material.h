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
	public:
		static SDL2_Material *create(Math::vec2 size = Math::vec2(100, 100), Math::vec4 color = Math::vec4::vec4_zero);
		static SDL2_Material *create(std::string path);
		~SDL2_Material();

		//	显示
		void show();

		//	设置位置
		void setPosition(Math::vec2 position);

		//	设置尺寸
		void setSize(Math::vec2 size);
	private:
		SDL2_Material(SDL_Surface *sur);

	private:
		WaterBox::Math::vec2 m_Position;
		WaterBox::Math::vec2 m_Size;
		SDL_Texture *m_Tex;

	};
}
#endif	//	!_SDL2_MATERIAL_H_BOX