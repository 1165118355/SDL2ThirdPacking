///////////////////////////////
//	this class is a Utils in c++.
//	这是一个工具集
//	《Ttils类》
//	2018年8月18日 11:59:26
//	by	水华宝箱

#ifndef _SDL2_UTILS_H_BOX
#define _SDL2_UTILS_H_BOX

#include <string>

namespace WaterBox
{
	class SDL2_Utils
	{
	public:
		static SDL2_Utils *get();

		///	\brief	将字符串转换成int类型（保证字符串中都是数字）该函数会处理字符串中后缀的计算
		int StrToInt(std::string string);
		~SDL2_Utils();
	private:
		SDL2_Utils();
	private:
		static SDL2_Utils *m_Utils;
	};
}

#endif // !_SDL2_UTILS_H_BOX