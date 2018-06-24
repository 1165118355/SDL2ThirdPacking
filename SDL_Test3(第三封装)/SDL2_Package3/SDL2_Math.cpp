#include "SDL2_Math.h"

using namespace WaterBox;
const Math::vec4 Math::vec4::vec4_zero = Math::vec4(0, 0, 0, 0);
const Math::vec2 Math::vec2::vec2_zero = Math::vec2(0, 0);
WaterBox::Math::vec2::vec2()
{
	x = 0;
	y = 0;
}

WaterBox::Math::vec2::vec2(double x, double y) 
{
	vec2::x = x;
	vec2::y = y;
}

WaterBox::Math::vec3::vec3() 
{
	x = 0;

}

WaterBox::Math::vec3::vec3(double x, double y, double z)
{
	vec3::x = x;
	vec3::y = y;
	vec3::z = z;
}

WaterBox::Math::vec4::vec4(double x, double y, double z, double w)
{
	vec4::x = x;
	vec4::y = y;
	vec4::z = z;
	vec4::w = w;
}
