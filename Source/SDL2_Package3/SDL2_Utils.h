///////////////////////////////
//	this class is a Utils in c++.
//	����һ�����߼�
//	��Ttils�ࡷ
//	2018��8��18�� 11:59:26
//	by	ˮ������

#ifndef _SDL2_UTILS_H_BOX
#define _SDL2_UTILS_H_BOX

#include <string>

namespace WaterBox
{
	class SDL2_Utils
	{
	public:
		static SDL2_Utils *get();

		///	\brief	���ַ���ת����int���ͣ���֤�ַ����ж������֣��ú����ᴦ���ַ����к�׺�ļ���
		int StrToInt(std::string string);
		~SDL2_Utils();
	private:
		SDL2_Utils();
	private:
		static SDL2_Utils *m_Utils;
	};
}

#endif // !_SDL2_UTILS_H_BOX