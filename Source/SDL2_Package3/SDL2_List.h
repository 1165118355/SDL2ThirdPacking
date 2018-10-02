///////////////////////////////
//	this class is a List in SDL2.
//	UI������б�
//	���б��ࡷ
//	2018��9��22�� 23:57:59
//	by	ˮ������

#ifndef _SDL2_LIST_H_BOX
#define _SDL2_LIST_H_BOX

#include <SDL2_Component.h>
#include <SDL2_ListItem.h>
#include <SDL2_VBox.h>

namespace WaterBox
{
	class SDL2_ListItem;
	class SDL2_List : public SDL2_Component
	{
	public:
		friend SDL2_ListItem;
		~SDL2_List();
		static SDL2_List *create();
		static SDL2_List *create(SDL2_Xml *xml);

		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	������£������¼���⣬�߼��жϣ�
		virtual void update(SDL_Event *event);

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		///	brief	��ʾ����
		virtual void show();

		///	\brief	��ȡmaterial������
		virtual std::vector<SDL2_Material *> getMaterials();

		///	\brief	��������¼�
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	���¼����¼�
		virtual void updateEventKeyboard(SDL_Event *event);

		///	\brief	���ñ�������
		void setMaterialBack(SDL2_Material *material);

		///	\brief	�������
		void addItem(std::string name);

		///	\brief	�������
		void addItem(SDL2_ListItem *item);

		///	\brief	�Ƴ�ĳ������
		void removeItem();

		///	\brief	ѡ��ĳ������
		void selectItem(int num);

		///	\brief	������������״̬�����е����
		void clear();

	private:
		SDL2_List();

	private:
		SDL2_VBox *m_ListBox;
		std::vector<SDL2_ListItem *> m_ListItems;
		SDL2_Material *m_MaterialBack;
		int m_CurrentTopItem;
		int m_CurrentItem;
	};
}

#endif	//!_SDL2_LIST_H_BOX


/*
xml˵��
	tag˵��
		material_back="null"		//	�����Ĳ���		������ͼƬ�����Ƕ�����
	name˵��
		<list>						//	���־��������
*/