///////////////////////////////
//	this class is a Material in SDL2. Save the Material use the class please.
//	���ʵ����࣬һ��������������в��ʵĴ洢
//	�������ࡷ
//	2018��6��23�� 23:58:53
//	by	ˮ������

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
		///	�������͵�ö��
		enum MaterialType
		{
			TYPE_PARENT = 0,	//	���Ǹ���
			TYPE_PICTURE,		//	ͼƬ������
			TYPE_ANIMAL,		//	����������
			TYPE_TEXT			//	���ֲ�����
		};
	public:
		static SDL2_Material *create();
		~SDL2_Material();

		//	����λ��
		void setPosition(Math::vec2 position);
		Math::vec2 getPosition();

		//	���óߴ�
		void setSize(Math::vec2 size);
		Math::vec2 getSize();

		//	��ʾ
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