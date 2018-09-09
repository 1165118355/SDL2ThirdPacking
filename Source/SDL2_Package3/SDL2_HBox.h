///////////////////////////////
//	this class is a VBox in SDL2.
//	��Ҫ����װ������������Ǹ������������������
//	�����������ࡷ
//	2018��6��25�� 22:07:47
//	by	ˮ������

#pragma once
#include <SDL2_Component.h>
#include <SDL2_Box.h>
#include <SDL2_Xml.h>
#include <vector>
namespace WaterBox
{
	class SDL2_HBox :public SDL2_Box
	{
	public:
		static SDL2_HBox *create(Math::vec2 position = Math::vec2(0, 0));
		static SDL2_HBox *create(SDL2_Xml *xml);

		///	brief	�����¼�
		virtual void update(SDL_Event *event);

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		/// brief	������ʾ����ĺ���
		virtual void show();
		
		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	����������������
		void addComponent(SDL2_Component *component);

		///	breif	���һ�������
		virtual void addChild(SDL2_Component *child);
	private:
		SDL2_HBox();
	private:
		int m_Spacing;
	};
}