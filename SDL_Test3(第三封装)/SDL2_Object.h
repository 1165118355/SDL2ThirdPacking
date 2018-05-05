#pragma once
#include <SDL2_Math.h>
namespace WaterBox
{
	class SDL2_Object
	{
	public:
		SDL2_Object();
	private:
		Math::vec2 position;
	};
}