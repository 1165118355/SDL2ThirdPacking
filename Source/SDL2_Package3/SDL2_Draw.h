///////////////////////////////
//	this class is a Draw in SDL2.let draw point, draw line...... use the class
//	用来画画，画点线面等
//	《画画类》
//	2018年6月23日 23:48:30
//	by	水华宝箱
#pragma once
#include <SDL2_Object.h>
namespace WaterBox
{
	class SDL2_Draw
	{
	public:
		///	brief 画一个点
		static void drawPoint(Math::vec2 position, Math::vec4 color);

		///	brief 画一条线
		static void drawLine(Math::vec2 position1, Math::vec2 position2, Math::vec4 color);

		///	brief 画一个矩形
		static void drawRectangle(Math::vec2 position, Math::vec2 size, Math::vec4 color);
	private:

	};
}