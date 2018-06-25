///////////////////////////////
//	this class is a Label in SDL2.
//	��ǩ����Ҫ����ʾ����
//	����ǩ�ࡷ
//	2018��6��25�� 22:05:19
//	by	ˮ������

#pragma once
#include <string>
#include <SDL2_MaterialText.h>
#include <SDL2_Component.h>
namespace WaterBox 
{
	class SDL2_Label: public SDL2_Component
	{
	public:
		static SDL2_Label *create(std::string text="label");
		virtual void show();
		virtual void update(SDL_Event *event);

		virtual void setPosition(Math::vec2 position);

		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();
	private:
		SDL2_Label(std::string text);
	private:
		std::string m_Text;
		SDL2_Material *m_MaterialText;

	};
}