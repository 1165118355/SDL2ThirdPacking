///////////////////////////////
//	this class is a Image in SDL2 
//	ͼ����
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
		///	����һ��GuiImage��ɫ�ʵ�
		static SDL2_Image *create();

		///	����һ������ͼƬ��GuiImage������1��ͼƬ·��
		static SDL2_Image *create(std::string path);

		///	����һ������ͼƬ��GuiImage������1�ǲ���
		static SDL2_Image *create(SDL2_Material *mat);

		///	��ʾ��UI
		virtual int show();

		virtual void update(SDL_Event *event);

		///
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	���ø�GuiImage�Ĳ��ʣ�ͼ���ڲ����У�
		void setMaterial(SDL2_Material *mat);
		SDL2_Material *getMaterial();
	protected:

	private:
		SDL2_Image(SDL2_Material *mat);
	private:
		SDL2_Material *m_Material;
	};
}

#endif// !_SDL2_IMAGE_H_BOX