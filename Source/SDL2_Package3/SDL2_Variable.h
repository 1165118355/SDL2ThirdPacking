///////////////////////////////
//	this class is a Variable in SDL2.
//	存储多种类型变量
//	《变量类》
//	2018年10月13日 05:40:46
//	by	水华宝箱
#ifndef _SDL2_VARIABLE_H_BOX_
#define _SDL2_VARIABLE_H_BOX_

#include <string>

class SDL2_Variable
{
public:
	SDL2_Variable();
	~SDL2_Variable();

	///	\brief	字符串
	void setString(std::string);
	std::string getString();

	///	\brief	整数
	void setInt(int num);
	int getInt();

	///	\brief	单精度浮点数
	void setFloat(float num);
	float getFloat();

	///	\brief	双精度浮点数
	void setDouble(double num);
	double getDouble();
private:
	double			m_Double;
	float			m_Float;
	int				m_Int;
	std::string		m_String;
};
#endif//!_SDL2_VARIABLE_H_BOX_

