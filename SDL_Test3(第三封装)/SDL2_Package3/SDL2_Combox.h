///////////////////////////////
//	this class is a Combox in SDL2.
//	����һ���༭��
//	�������б��ࡷ
//	2018��6��26�� 21:36:25
//	by	ˮ������
#pragma once
#include <vector>
#include <SDL2_Component.h>
#include <SDL2_Math.h>
#include <SDL2_Material.h>

namespace WaterBox
{
	class SDL2_Combox :public SDL2_Component
	{
	public:
		static SDL2_Combox *create();

		///	brief	����������ѡ�����ı��
		int getValue();

		///	brief	���һ��
		void addItem(std::string itmeName);

		///	brief	���ò��ʣ��������ģ�һ����Material_Picture��
		void setMaterialBox(SDL2_Material *matBox);
		void setMaterialItem(SDL2_Material *matItem);

		//void setTextSpace(int space);

		///	brief	����λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	���óߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	��ʾ����
		virtual void show();

		///	brief	�����¼�����
		virtual void update(SDL_Event *event);

	private:
		SDL2_Combox();

	private:
		int m_Value;										//	�Ҿ��ý�index���ܻ��Щ
		int m_PreValue;										//	Ԥѡ�����ָ�ŵ�Item
		int m_ChooseFlag;									//	չ����־��չ�������б�
		int m_Space;										//	�ı�������back֮�����ܵļ��
		std::vector<std::string> m_ItemName;				//	Item������

		std::vector<SDL2_Material *> m_MaterialText;		
		SDL2_Material *m_MaterialBox;
		SDL2_Material *m_MaterialItem;
		
	};
}