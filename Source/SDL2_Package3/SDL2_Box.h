///////////////////////////////
//	this class is a VBox in SDL2.
//	��Ҫ����װ������������Ǹ�������
//	����������ࡷ
//	2018��7��7�� 23:27:29
//	by	ˮ������
#pragma once
#include <SDL2_Component.h>
#include <vector>

namespace WaterBox
{
	class SDL2_Box :public SDL2_Component
	{
	public:
		virtual ~SDL2_Box();
		static SDL2_Box *cast(SDL2_Component *component);

		///	\brief	����������������
		virtual void addComponent(SDL2_Component *component);

		///	\brief	��ȡ���������
		virtual int getNumComponents();
		virtual SDL2_Component *getComponent(int num);

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		///	\brief	��ʾ
		virtual void show();

		/// \brief	�����¼�
		virtual void update(SDL_Event *event);

		///	\brief	����ɾ�����������
		virtual void clear();

		///	\brief	��������¼�
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	���¼����¼�
		virtual void updateEventKeyboard(SDL_Event *event);

	protected:
		SDL2_Box();
	protected:
		std::vector<SDL2_Component *> m_Components;
	private:
	};
}