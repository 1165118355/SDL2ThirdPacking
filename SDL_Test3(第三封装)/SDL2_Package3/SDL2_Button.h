///////////////////////////////
//	this class is a Button in SDL2 
//	��ť��
//	2018��6��9�� 08:18:50
//	by	ˮ������
#pragma once
#include <string>
#include <SDL2_Component.h>
#include <SDL2_Material.h>


namespace WaterBox
{
	class SDL2_Button :public SDL2_Component
	{
	public:
		///	brief ������ǿ��ת����Button
		static SDL2_Button *cast(SDL2_Component *componet);

		///	����һ��Button����ɫ�ʵģ�
		static SDL2_Button *create(std::string text="button");

		///	����һ��Button ��ͼƬ��
		static SDL2_Button *create(std::string path1, std::string path2, std::string text = "button");

		///	��ʾ��Gui���
		virtual void show();

		virtual void update(SDL_Event *event);

		void setCallback(int *(*Callback)(void *ptr));

		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	���ð�ť�Ƿ񱻰���
		void setFlag(int flag);
		int getFlag();
	private:
		SDL2_Button(SDL2_Material *matBefor, SDL2_Material *matAfter, SDL2_Material *matText);
	private:
		int m_Flag;
		int *(*m_Callback)(void *ptr);
		SDL2_Material *m_MaterialBefore;
		SDL2_Material *m_MaterialAfter;
		SDL2_Material *m_MaterialText;
	};
}