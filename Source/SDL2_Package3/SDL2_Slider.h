///////////////////////////////
//	this class is a Slider in SDL2, let's move the slider use the mouse .
//	������
//	2018��6��23�� 23:43:45
//	by	ˮ������
#pragma once
#include <string>
#include <SDL2_Material.h>
#include <SDL2_Component.h>
#include <SDL2_Xml.h>

namespace WaterBox
{
	class SDL2_Slider : public SDL2_Component
	{
	public:
		enum SliderType
		{
			SLIDER_VERTICAL,
			SLIDER_HORIZONTAL
		};
	public:
		///	\brief ������ǿ��ת����Button
		static SDL2_Slider *cast(SDL2_Component *componet);

		///	brief	����һ����������Ҫָ�����ȣ���ª�棩
		static SDL2_Slider *create(int length);

		///	brief	����һ����������Ҫָ������(��Ҫ����ͼƬ)
		static SDL2_Slider *create(int length, std::string cakeBack, std::string cakePath);

		///	\brief	����xml����Ϣ����һ��slider
		static SDL2_Slider *create(SDL2_Xml *xml);

		///	brief	���û�����λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	\brief	���û���������
		void setSliderType(SliderType type);
		SliderType getSliderType();

		///	\brief	���û����ĳ���
		void setLength(int length);
		int getLength();

		///	\brief	���ñ����Ĳ���
		void setMaterialBack(SDL2_Material *matBack);
		SDL2_Material *getMaterialBack();

		///	\brief	���û���Ĳ���
		void setMaterialCake(SDL2_Material *matCake);
		SDL2_Material *getMaterialCake();

		///	brief	���û���ֵ�����ǻ�ȡֵ����ӡ�������¾�֪���ˣ�
		void setValue(int value);
		int getValue();

		///	\breif	���û��������ֵ
		void setValueMax(int valueMax);
		int getValueMax();
		
		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	���¸����
		virtual void update(SDL_Event *event);

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		///	\brief	��ʾ�����
		virtual void show();

	private:
		SDL2_Slider();

		///	brief	���û����ĳߴ�(���Ƽ�ʹ��������Ƽ�ʹ�õ���setLength()��Ϊ������û�����ú��ѿ�)
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();
	private:
		SDL2_Material *m_MaterialBack;			//	��������������Ǹ���
		SDL2_Material *m_MaterialCake;			//	���飨����϶��Ǹ���
		double m_CakeValue;						//	�����ֵ
		double m_CakeValueMax;					//	��������ֵ
		int m_Length;							//	�����ĳ���
		Math::vec2 m_CakePos;					//	��ˮ��
		Math::vec2 m_CakeSize;
		SliderType m_SliderType;				//	�洢���������
	};
}


/*
xml˵��
	tag˵��
		path_back="null"		//	���鱳�����Ǹ�������ͼƬ·��		������ͼƬ�����Ƕ�����
		path_cake="null"		//	����ͼƬ��·��						������ͼƬ�����Ƕ�����
	name˵��
		<slider>				//	���־��������
*/