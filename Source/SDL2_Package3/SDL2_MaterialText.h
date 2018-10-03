///////////////////////////////
//	this class is a Text in SDL2. 
//	���ʣ����Դ洢���֣���������ͼƬ����ʽ���ڣ�
//	�����ֲ����ࡷ
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
	class SDL2_MaterialText :public SDL2_Material
	{
	public:
		~SDL2_MaterialText();
		static SDL2_MaterialText *cast(SDL2_Material *material);
		///	brief	����һ�����ֲ��ʣ����߸������ַ���
		static SDL2_MaterialText *create();

		///	brief	����һ�����ֲ��ʣ����߸������ַ���
		static SDL2_MaterialText *create(std::string text);

		///	brief	��ʾ���ֲ��ʵĺ���
		virtual void show();

		///	brief	������ʾ�ı�
		void setText(std::string text, Math::vec4 color = Math::vec4(0, 0, 0, 255));
		std::string getText();

		virtual int load(SDL2_Xml *xml);
		virtual SDL2_Xml *save();

		///	\brief	���¼���������ʣ�һ�����ڶര����Ⱦʱ�õ���
		virtual void reload();
	private:
		SDL2_MaterialText();

	private:
		Math::vec4 m_Color;						//	�ַ�������ɫ
		std::string m_Text;						//	�ַ���������洢��Ҫ��ʾ���ַ���
		SDL_Texture *m_Texture;					//	SDL������
	};
}