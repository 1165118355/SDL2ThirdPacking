///////////////////////////////
//	this class is a Node in SDL2.
//	��ʾһ�����壬���Ǻܶ�����Ļ���
//	���ڵ��ࡷ
//	2018��8��13�� 20:08:34
//	by	ˮ������
#ifndef _SDL2_NODE_H_BOX
#define _SDL2_NODE_H_BOX

#include <string>
#include <SDL2_Math.h>
#include <SDL2/SDL.h>

namespace WaterBox
{
	class SDL2_Node
	{
	public:
		///	brief	������һ��
		virtual ~SDL2_Node();

		/// brief	����λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();
		
		///	brief	���óߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	��������
		virtual void setName(std::string name);
		virtual std::string getName();

		///	\brief	��ȡ��Node��id
		virtual int getId();

		///	\brief	�����¼�
		virtual void updateEvent(SDL_Event *event);

		///	\brief	��������¼�
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	���¼����¼�
		virtual void updateEventKeyboard(SDL_Event *event);

	protected:
		SDL2_Node();
	protected:
		Math::vec2 m_Position;
		Math::vec2 m_Size;
		std::string m_Name;
		int m_Id;
		SDL2_Node *m_Self;
	};
}

#endif // !_SDL2_NODE_H_BOX