///////////////////////////////
//	this class is a Image in SDL2 
//	UIͼ����
//	2018��6��9�� 08:18:50
//	by	ˮ������

#ifndef _SDL2_IMAGE_H_BOX
#define _SDL2_IMAGE_H_BOX

#include <SDL2_Component.h>
#include <SDL2_Material.h>
#include <SDL2/SDL.h>

namespace WaterBox
{
	class SDL2_Image:public SDL2_Component
	{
	public:
		///	brief	����һ������ͼƬ��GuiImage������1��ͼƬ·��
		static SDL2_Image *create(std::string path);

		///	brief	����һ������ͼƬ��GuiImage������1�ǲ���
		static SDL2_Image *create(SDL2_Material *mat);

		///	brief	��ʾ��UI
		virtual void show();

		///	brief	���¸�UI
		virtual void update(SDL_Event *event);

		/// brief	����imageλ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		/// brief	����image�ߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	���ø�GuiImage�Ĳ��ʣ�ͼ���ڲ����У�
		void setMaterial(SDL2_Material *mat);
		SDL2_Material *getMaterial();

		///	brief	����ͼ��͸����
		virtual void setTransparent(int transparent);
		virtual int getTransparent();

	private:
		SDL2_Image(SDL2_Material *mat);

	private:
		SDL2_Material *m_Material;
	};
}

#endif// !_SDL2_IMAGE_H_BOX