///////////////////////////////
//	this class is a Slider in SDL2, let's move the slider use the mouse .
//	������
//	2018��6��23�� 23:43:45
//	by	ˮ������
#pragma once
#include <string>
#include <SDL2_Material.h>
#include <SDL2_Component.h>
namespace WaterBox
{
	class SDL2_Slider : public SDL2_Component
	{
	public:
		enum SliderType
		{
			VERTICAL,
			HORIZONTAL
		};
	public:
		///	brief	����һ����������Ҫָ�����ȣ���ª�棩
		static SDL2_Slider *create(int length);

		///	brief	����һ����������Ҫָ������(��Ҫ����ͼƬ)
		static SDL2_Slider *create(int length, std::string cakeBack, std::string cakePath);

		///	brief	���û�����λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	���û����ĳߴ�(���Ƽ�ʹ��������Ƽ�ʹ�õ���setLength()��Ϊ������û�����ú��ѿ�)
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	��ȡ����ֵ�����ǻ�ȡֵ����ӡ�������¾�֪���ˣ�
		int getValue();
		
		virtual void show();
		virtual void update(SDL_Event *event);
	private:
		SDL2_Slider(int length, SDL2_Material *matBack, SDL2_Material *matCake);
	private:
		SDL2_Material *m_MaterialBack;			//	��������������Ǹ���
		SDL2_Material *m_MaterialCake;			//	���飨����϶��Ǹ���
		double m_CakeValue;						//	�����ֵ
		double m_CakeValueMax;					//	��������ֵ
		Math::vec2 m_CakePos;					//	��ˮ��
		Math::vec2 m_CakeSize;
	};
}