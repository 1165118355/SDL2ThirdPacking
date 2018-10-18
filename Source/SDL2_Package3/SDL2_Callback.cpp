#include "SDL2_Callback.h"

using namespace WaterBox;


void WaterBox::SDL2_CallbackBase::run()
{
}

void WaterBox::SDL2_CallbackBase::setParmNumber(int parm)
{
	m_ParmNumber = parm;
}
int WaterBox::SDL2_CallbackBase::getParmNumber()
{
	return m_ParmNumber;
}