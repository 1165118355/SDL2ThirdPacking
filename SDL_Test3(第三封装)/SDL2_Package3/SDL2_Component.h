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

#include <SDL2_Math.h>
#include <SDL2/SDL.h>
namespace WaterBox
{
	class SDL2_Component
	{
	public :
		enum Type
		{
			COMPONENT_BUTTON=0	,
			COMPONENT_IMAGE		,
			COMPONENT_WINDOW	,
			COMPONENT_CHECKBOX	,
			COMPONENT_LABEL		,
			COMPONENT_HBOX		,
			COMPONENT_VBOX		,
			COMPONENT_EDITLINE	,
		};
	public :

		//	���������λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		//	��������ĳߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		//	��ȡ�������
		virtual Type getType() { return type; }
		virtual void show()=0;

		//	������£������¼���⣬�߼��жϣ�
		virtual void update(SDL_Event *event)=0;
	protected:
		Type type;
		Math::vec2 m_Position;
		Math::vec2 m_Size;
	private:
	};
}

#endif// !_SDL2_COMPONENT_BOX