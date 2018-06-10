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
		///	����һ��Button����ɫ�ʵģ�
		static SDL2_Button *create();

		///	����һ��Button ��ͼƬ��
		static SDL2_Button *create(std::string path1, std::string path2);

		///	��ʾ��Gui���
		virtual int show();

		void setCallback(int *(*Callback)(void *ptr) );

		///	���ð�ť�Ƿ񱻰���
		void setFlag(int flag);
		int getFlag();
	private:
		SDL2_Button(SDL2_Material *matBefor, SDL2_Material *matAfter);
	private:
		int m_Flag;
		int *(*m_Callback)(void *ptr);
		SDL2_Material *m_MaterialBefore;
		SDL2_Material *m_MaterialAfter;
	};
}