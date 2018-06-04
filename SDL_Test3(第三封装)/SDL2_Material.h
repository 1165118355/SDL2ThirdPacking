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
		SDL2_Material(Math::vec2 size = Math::vec2(100, 100), Math::vec4 color = Math::vec4::vec4_zero);
		SDL2_Material(std::string name);
		~SDL2_Material();

		//	��ʾ
		void show();

		//	����λ��
		void setPosition(Math::vec2 position);

		//	���óߴ�
		void setSize(Math::vec2 size);
	private:
		WaterBox::Math::vec2 m_Position;
		WaterBox::Math::vec2 m_Size;
		SDL_Texture *m_Tex;

	};
}
#endif	//	!_SDL2_MATERIAL_H_BOX