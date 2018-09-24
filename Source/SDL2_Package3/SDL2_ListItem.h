///////////////////////////////
//	this class is a ListItem in SDL2.
//	UI������б������
//	���б������ࡷ
//	2018��9��23�� 00:20:44
//	by	ˮ������

#ifndef _SDL2_LISTITEM_H_BOX
#define _SDL2_LISTITEM_H_BOX

#include <SDL2_Component.h>
#include <SDL2_Label.h>
#include <SDL2_List.h>

namespace WaterBox
{
	class SDL2_List;
	class SDL2_ListItem :
		public SDL2_Component
	{
		friend SDL2_List;
	public:
		enum ListItemState
		{
			LISTITEM_RELEASE,
			LISTITEM_SELECTED,
			LISTITEM_HOVER
		};
	public:
		~SDL2_ListItem();
		static SDL2_ListItem *create(std::string name="");

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

		///	\brief	����������һ��lable
		void setText(std::string text);
		std::string getText();

		///	\brief	���������״̬
		void setSelected(ListItemState selct);
		ListItemState getSelected();

		///	\brief	���ظ��б�
		SDL2_List *getList();

		///	\brief	�����������
		int getIndex();
	private:
		SDL2_ListItem();

		///	\brief	���ø��б���
		void setList(SDL2_List *list);

		///	\brief	�����������
		void setIndex(int index);
	private:
		int m_Index;								//	���б��еı��
		SDL2_List *m_List;							//	�洢���б�
		std::vector<SDL2_Component *> m_Components;	//	��������
		SDL2_Label *m_Lable;						//	Ĭ��һ����һ��lable
		SDL2_Material *m_MaterialBack;				//	�������
		Math::vec4 m_ColorBackDefault;				//	Ĭ�ϵı�����ɫ
		ListItemState m_Select;						//	���������״̬
	};
}
#endif	//!_SDL2_LIST_H_BOX