///////////////////////////////
//	this class is a Slider in SDL2, let's move the slider use the mouse .
//	滑条类
//	2018年6月23日 23:43:45
//	by	水华宝箱
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
			VERTICAL,
			HORIZONTAL
		};
	public:
		///	brief	创建一个滑条，需要指定长度（简陋版）
		static SDL2_Slider *create(int length);

		///	brief	创建一个滑条，需要指定长度(需要两张图片)
		static SDL2_Slider *create(int length, std::string cakeBack, std::string cakePath);

		///	\brief	根据xml的信息创建一个slider
		static SDL2_Slider *create(SDL2_Xml *xml);

		///	brief	设置滑条的位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	\brief	设置滑条的长度
		void setLength(int length);
		int getLength();

		///	\brief	设置背景的材质
		void setMaterialBack(SDL2_Material *matBack);
		SDL2_Material *getMaterialBack();

		///	\brief	设置滑块的材质
		void setMaterialCake(SDL2_Material *matCake);
		SDL2_Material *getMaterialCake();

		///	brief	设置滑块值（就是获取值，打印出来看下就知道了）
		void setValue(int value);
		int getValue();

		///	\breif	设置滑条的最大值
		void setValueMax(int valueMax);
		int getValueMax();
		
		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	显示该组件
		virtual void show();

		///	\brief	更新该组件
		virtual void update(SDL_Event *event);
	private:
		SDL2_Slider();

		///	brief	设置滑条的尺寸(不推荐使用这个，推荐使用的是setLength()因为这个会让滑条变得很难看)
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();
	private:
		SDL2_Material *m_MaterialBack;			//	滑条（滑块后面那个）
		SDL2_Material *m_MaterialCake;			//	滑块（鼠标拖动那个）
		double m_CakeValue;						//	滑块的值
		double m_CakeValueMax;					//	滑块的最大值
		int m_Length;							//	滑条的长度
		Math::vec2 m_CakePos;					//	划水用
		Math::vec2 m_CakeSize;
	};
}


/*
xml说明
	tag说明
		path_back="null"		//	滑块背景的那个滑条的图片路径		（仅限图片不能是动画）
		path_cake="null"		//	滑块图片的路径						（仅限图片不能是动画）
	name说明
		<slider>				//	名字就是这个咯
*/