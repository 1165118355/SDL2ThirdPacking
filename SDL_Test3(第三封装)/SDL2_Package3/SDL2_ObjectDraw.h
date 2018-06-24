#pragma once
#include <SDL2_Object.h>

namespace WaterBox
{
	class SDL2_ObjectDraw :public SDL2_Object
	{
	public :
		enum DrawType
		{
			DRAW_POINT = 0,
			DRAW_LINE,
			DRAW_RECTANGLE,
			DRAW_SPHERE
		};
	public:
		static SDL2_ObjectDraw *createPoint(Math::vec2 position);
		static SDL2_ObjectDraw *createLine(Math::vec2 position1, Math::vec2 position2);
		static SDL2_ObjectDraw *createRectangle(Math::vec2 position, Math::vec2 size);
		static SDL2_ObjectDraw *createSphere(Math::vec2 position, int radius);

	private:
		SDL2_ObjectDraw();
	private:
		DrawType m_Type;

	};
}