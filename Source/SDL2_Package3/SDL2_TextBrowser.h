///////////////////////////////
//	this class is a VBox in SDL2.
//	��Ҫ����װ������������Ǹ�������
//	����������ࡷ
//	2018��7��7�� 23:27:29
//	by	ˮ������

#ifndef _SDL2_TEXTBROWSER_H_BOX
#define _SDL2_TEXTBROWSER_H_BOX

#include <SDL2_Component.h>

namespace WaterBox
{
	class SDL2_TextBrowser : public SDL2_Component
	{
	public:
		~SDL2_TextBrowser();
		static SDL2_TextBrowser *create();

		///	\brief	����
		virtual void update(SDL_Event *event);

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		///	\brief ��ʾ��Gui���
		virtual void show();

		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	��ȡ���е�material
		virtual std::vector<SDL2_Material *> getMaterials();

		///	\brief	��������¼�
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	���¼����¼�
		virtual void updateEventKeyboard(SDL_Event *event);

	private:
		SDL2_TextBrowser();
	private:
		SDL2_Material *m_MaterialBack;

	};
}

#endif // !_SDL2_TEXTBROWSER_H_BOX
