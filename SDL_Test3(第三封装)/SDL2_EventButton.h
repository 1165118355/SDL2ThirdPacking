#pragma once
#include <SDL2_Event.h>
namespace WaterBox
{
	class SDL2_EventButton :public SDL2_Event
	{
	public:
		virtual int checkEvent(SDL2_Component *component);
	private:

	};
}