///////////////////////////////
//	this class is a Draw in SDL2.let draw point, draw line...... use the class
//	�������������������
//	�������ࡷ
//	2018��6��23�� 23:48:30
//	by	ˮ������
#pragma once
#include <SDL2_Object.h>
namespace WaterBox
{
	class SDL2_Draw
	{
	public:
		///	brief ��һ����
		static void drawPoint(Math::vec2 position, Math::vec4 color);

		///	brief ��һ����
		static void drawLine(Math::vec2 position1, Math::vec2 position2, Math::vec4 color);

		///	brief ��һ������
		static void drawRectangle(Math::vec2 position, Math::vec2 size, Math::vec4 color);
	private:

	};
}