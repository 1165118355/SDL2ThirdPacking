///////////////////////////////
//	this class is a Slider in SDL2, let's move the slider use the mouse .
//	滑条类
//	2018年6月23日 23:43:45
//	by	水华宝箱
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
		///	brief	创建一个滑条，需要指定长度（简陋版）
		static SDL2_Slider *create(int length);

		///	brief	创建一个滑条，需要指定长度(需要两张图片)
		static SDL2_Slider *create(int length, std::string cakeBack, std::string cakePath);

		///	brief	设置滑条的位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	设置滑条的尺寸(不推荐使用这个，推荐使用的是setLength()因为这个会让滑条变得很难看)
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	获取滑块值（就是获取值，打印出来看下就知道了）
		int getValue();
		
		virtual void show();
		virtual void update(SDL_Event *event);
	private:
		SDL2_Slider(int length, SDL2_Material *matBack, SDL2_Material *matCake);
	private:
		SDL2_Material *m_MaterialBack;			//	滑条（滑块后面那个）
		SDL2_Material *m_MaterialCake;			//	滑块（鼠标拖动那个）
		double m_CakeValue;						//	滑块的值
		double m_CakeValueMax;					//	滑块的最大值
		Math::vec2 m_CakePos;					//	划水用
		Math::vec2 m_CakeSize;
	};
}