///////////////////////////////
//	this class is a Picture in SDL2. use the class ,save the Picture
//	���ʣ����Դ洢ͼƬ
//	��ͼƬ�����ࡷ
//	2018��6��23�� 23:58:53
//	by	ˮ������

#pragma once
#include <string>
#include <SDL2_Math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2_Renderer.h>
#include <SDL2_Material.h>

namespace WaterBox
{
	class SDL2_MaterialPicture :public SDL2_Material
	{
	public:
		///	brief	����һ��ͼƬ���ʣ������ṩ��·��
		static SDL2_MaterialPicture *create(std::string path);

		///	brief	��ʾͼƬ�ĺ���
		virtual void show();

	private:
		SDL2_MaterialPicture(SDL_Texture *tex);

	private:
		SDL_Texture *m_Texture;				//	SDL������
	};
}