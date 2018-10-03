///////////////////////////////
//	this class is a EditLine in SDL2.
//	����һ���༭��
//	���༭���ࡷ
//	2018��6��25�� 22:05:51
//	by	ˮ������

#pragma once
#include <SDL2_Component.h>
#include <SDL2_Material.h>
#include <SDL2_Label.h>
#include <string>

namespace WaterBox
{
	class SDL2_EditLine :public SDL2_Component
	{
	public :
		///	brief	����һ���༭��
		static SDL2_EditLine *create();
		
		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	�����¼�����
		virtual void update(SDL_Event *event);

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		///	brief	��ʾ����
		virtual void show();

		///	\brief	��������¼�
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	���¼����¼�
		virtual void updateEventKeyboard(SDL_Event *event);

		///	\brief	��ȡ�����Ĳ���
		void setMaterialBack(SDL2_Material *material);
		SDL2_Material *getMaterialBack();

		///	\brief	����Editline�е���Ϣ
		void setText(std::string text);
		std::string getText();

		///	\brief	���ñ�����ɫ(����Ĭ�ϲ���)
		void setColorBackGround(Math::vec4 color);
		Math::vec4 getColorBackGround();

		///	\brief	����������ɫ
		void setColorFont(Math::vec4 color);
		Math::vec4 getColorFont();

		///	\brief	�����α���ɫ
		void setColorCursor(Math::vec4 color);
		Math::vec4 getColorCursor();

		///	\brief	�����ַ���
		void clear();
	private:
		SDL2_EditLine();

	private:
		SDL2_Material *m_MaterialBack;			//	��������
		Math::vec4 m_ColorBack;
		Math::vec4 m_ColorFont;
		Math::vec4 m_ColorCursor;

		std::string m_Text;						//	EditLine�д洢���ַ���
		std::vector<SDL2_Label*> m_ShowText;	//	��ʾ��Label��ÿһ���ַ�����һ��label
		int m_CurSorPos;						//	�α꣬�α����ַ����еڶ��ٸ��ַ���λ��
		int m_ShowStartPos, m_ShowEndPos;		//	��ʾ�ı��Ŀ�ʼλ�úͽ���Ϊֹ
		bool m_ChooseFlag;						//	�����Ƿ�������
		bool m_ChangeText;						//	���ı������仯�����������true
	};
}