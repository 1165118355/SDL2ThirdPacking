#pragma once

#include <SDL2_Component.h>
namespace WaterBox
{
	class SDL2_HBox
	{
	public:
		static SDL2_HBox *create();
		static SDL2_HBox *create(Math::vec2 position, Math::vec2 size);

		///	brief	����λ��
		virtual void setPosition();

		///	brief	���óߴ�
		virtual void setSize();

		///	brief	�����¼�
		virtual void update(SDL_Event *even);

		/// brief	������ʾ����ĺ���
		virtual int show();

		///	brief	����������������
	private:
		SDL2_HBox();
	};
}