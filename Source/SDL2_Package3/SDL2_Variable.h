///////////////////////////////
//	this class is a Variable in SDL2.
//	�洢�������ͱ���
//	�������ࡷ
//	2018��10��13�� 05:40:46
//	by	ˮ������
#ifndef _SDL2_VARIABLE_H_BOX_
#define _SDL2_VARIABLE_H_BOX_

#include <string>

class SDL2_Variable
{
public:
	SDL2_Variable();
	~SDL2_Variable();

	///	\brief	�ַ���
	void setString(std::string);
	std::string getString();

	///	\brief	����
	void setInt(int num);
	int getInt();

	///	\brief	�����ȸ�����
	void setFloat(float num);
	float getFloat();

	///	\brief	˫���ȸ�����
	void setDouble(double num);
	double getDouble();
private:
	double			m_Double;
	float			m_Float;
	int				m_Int;
	std::string		m_String;
};
#endif//!_SDL2_VARIABLE_H_BOX_

