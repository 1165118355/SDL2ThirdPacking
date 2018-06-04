#ifndef _SDL2_MATH_H_BOX
#define _SDL2_MATH_H_BOX
namespace WaterBox
{
	namespace Math
	{
		class vec2
		{
		public :
			vec2();
			vec2(double x, double y);
		public:
			static const vec2 vec2_zero;
			double x;
			double y;
		};

		class vec3
		{
		public:
			vec3();
			vec3(double x, double y, double z);
		
			double x;
			double y;
			double z;
		};

		class vec4
		{
		public:
			vec4();
			vec4(double x, double y, double z, double w);
		public:
			static const vec4 vec4_zero;
			double x;
			double y;
			double z;
			double w;
		};
	}
}

#endif	//	!_SDL2_MATH_H_BOX