///////////////////////////////
//	this class is a Component in SDL2.
//	�������������Ļ���
//	������ࡷ
//	2018��6��25�� 22:04:32
//	by	ˮ������

#ifndef _SDL2_COMPONENT_H_BOX
#define _SDL2_COMPONENT_H_BOX

/*
����Ļ���
*/
#include <SDL2_Node.h>
#include <SDL2_Math.h>
#include <SDL2_Xml.h>
#include <SDL2_MaterialManage.h>
#include <vector>
#include <SDL2/SDL.h>
namespace WaterBox
{
	class SDL2_Component :public SDL2_Node
	{
	public :
		enum ComponentType
		{
			COMPONENT_NONE = 0,
			COMPONENT_BUTTON,
			COMPONENT_IMAGE,
			COMPONENT_WINDOW,
			COMPONENT_CHECKBOX,
			COMPONENT_LABEL,
			COMPONENT_BOX_BEGINE,
			COMPONENT_BOX = COMPONENT_BOX_BEGINE,
			COMPONENT_HBOX,
			COMPONENT_VBOX,
			COMPONENT_DIALOG,
			COMPONENT_BOX_END = COMPONENT_DIALOG,
			COMPONENT_LIST,
			COMPONENT_LISTITEM,
			COMPONENT_EDITLINE,
			COMPONENT_COMBOX,
			COMPONENT_SLIDER
		};
		enum AlignType
		{
			ALIGN_NONE = 0,
			ALIGN_CENTER = 1,
			ALIGN_LEFT = 2,
			ALIGN_RIGHT = 4,
			ALIGN_TOP = 8,
			ALIGN_BOTTOM = 16
		};
		enum AlignMode
		{
			AMODE_NONE,
			AMODE_HORIZONTAL,
			AMODE_VERTICAL

		};
	public :

		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	������£������¼���⣬�߼��жϣ�
		virtual void update(SDL_Event *event) = 0;

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		///	brief	��ʾ����
		virtual void show() = 0;

		///	\brief	��ȡmaterial������
		virtual std::vector<SDL2_Material *> getMaterials();

		///	brief	���������λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	��������ĳߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	��ȡ�������
		virtual ComponentType getComponentType() { return m_ComponentType; }

		///	brief	��������ĸ����
		virtual void setParent(SDL2_Component *parent);
		
		///	breif	���һ�������
		virtual void addChild(SDL2_Component *child);

		///	brief	���ö��뷽ʽ���븸������룩
		virtual void setAlign(int align);
		virtual int getAlign();

		///	brief	�����������
		virtual void setName(std::string name);
		virtual std::string getName();

		///	\brief	��ȡ�����������
		int getNumChildes();
		SDL2_Component *getChild(int num);

	protected:
		//	�����������������Ű�
		virtual void Align();
	protected:
		std::string								m_Name;					//	�������
		ComponentType							m_ComponentType;		//	���������
		SDL2_Component*							m_Parent;				//	����ĸ����
		int										m_Align;				//	����Ķ��뷽ʽ�����ڸ������
		AlignMode								m_AMode;				//	��������ģʽ
		std::vector<SDL2_Component *>			m_Childes;				//	�������
		SDL2_Component();
	private:
	};
}

#endif// !_SDL2_COMPONENT_BOX

/*
xml˵��
	��׺˵��
		10xsp					//	����x��ı�������,10sp��ʾ1%��100sp��ʾ10%	�����������֣�
		10xsp					//	����y���������,10sp��ʾ1%��100sp��ʾ10%	�����������֣�
		10px					//	���أ�����1:1�����ؿ�				�����������֣�
	tag˵��
		x="0"					//	�����x����
		y="0"					//	�����y����
		w="0"					//	����Ŀ��
		h="0"					//	����ĸ߶�
		align="none"			//	
	name˵��
		<button>				//	��ť���
		<image>					//	ͼ�����
		<checkbox>				//	��ѡ��
		<combox>				//	�����б�
		<editline>				//	�༭��
		<label>					//	��ǩ�����֣�
		<slider>				//	����
		<hbox>
		<vbox>
		<window>
*/