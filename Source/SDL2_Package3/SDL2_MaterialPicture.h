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
		///	\brief	������ǿ��ת���������
		static SDL2_MaterialPicture *cast(SDL2_Material *mat);

		///	brief	����һ��ͼƬ���ʣ������ṩ��·��
		static SDL2_MaterialPicture *create();

		///	brief	����һ��ͼƬ���ʣ������ṩ��·��
		static SDL2_MaterialPicture *create(std::string path);


		///	brief	��ʾͼƬ�ĺ���
		virtual void show();

		///	\brief	���ò��ʵ�͸����
		virtual void setTransparent(int transparent);
		virtual int getTransparent();

		///	\brief	����ͼƬ��·��
		virtual int setPath(std::string path);
		virtual std::string getPath();

		///	\brief	����һ��xml
		virtual int load(SDL2_Xml *xml);
		virtual SDL2_Xml *save();
	private:
		SDL2_MaterialPicture();

	private:
		std::string m_Path;					//	����ͼƬ��·��
		SDL_Texture *m_Texture;				//	SDL������
	};
}

/*
xml����
	tag
		name=""					//	
		picture_path=""			//	�洢ͼƬ��·��

*/