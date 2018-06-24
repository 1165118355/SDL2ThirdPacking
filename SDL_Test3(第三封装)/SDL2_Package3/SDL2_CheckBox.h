#pragma once
#include <SDL2_Component.h>
#include <SDL2_Material.h>

namespace WaterBox
{
	class SDL2_CheckBox :public SDL2_Component
	{
	public:
		static SDL2_CheckBox *create();
		//static SDL2_CheckBox *create(SDL2_Material *matBack, SDL2_Material *matIn);

		///	brief	��ȡ��ѡ���Ƿ񱻹��ϣ���
		int getValue();

		///	brief	����λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPositioin();

		///	brief	���óߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	������ʾ
		virtual void show();

		///	brief	�����¼�
		virtual void update(SDL_Event *event);

	private:
		SDL2_CheckBox(SDL2_Material *matBack, SDL2_Material *matIn);

	private:
		int m_Value;
		SDL2_Material *m_MaterialBack;
		SDL2_Material *m_MaterialIn;

	};

}