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
		public:
			double x;
			double y;
			double z;
			double w;
		};
	}
}

#endif	//	!_SDL2_MATH_H_BOX