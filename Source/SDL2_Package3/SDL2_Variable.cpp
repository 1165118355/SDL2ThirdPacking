#include "SDL2_Variable.h"



SDL2_Variable::SDL2_Variable()
{
}


SDL2_Variable::~SDL2_Variable()
{
}

void SDL2_Variable::setString(std::string string)
{
	m_String = string;
}

std::string SDL2_Variable::getString()
{
	return m_String;
}

void SDL2_Variable::setInt(int num)
{
	m_Int = num;
}

int SDL2_Variable::getInt()
{
	return m_Int;
}

void SDL2_Variable::setFloat(float num)
{
	m_Float = num;
}

float SDL2_Variable::getFloat()
{
	return m_Float;
}

void SDL2_Variable::setDouble(double num)
{
	m_Double = num;
}

double SDL2_Variable::getDouble()
{
	return m_Double;
}
