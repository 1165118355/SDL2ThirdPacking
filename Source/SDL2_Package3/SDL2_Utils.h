///////////////////////////////
//	this class is a Utils in c++.
//	����һ�����߼�
//	��Ttils�ࡷ
//	2018��8��18�� 11:59:26
//	by	ˮ������

#ifndef _SDL2_UTILS_H_BOX
#define _SDL2_UTILS_H_BOX

#include <string>
#include <SDL2_Math.h>

namespace WaterBox
{
	class SDL2_Utils
	{
	public:
		static SDL2_Utils *get();

		///	\brief	���ַ���ת����int���ͣ���֤�ַ����ж������֣��ú����ᴦ���ַ����к�׺�ļ���
		int StrToInt(std::string string);

		///	\brief	�������ڼ��Ĵ��ڵĳߴ磨�봰���޹أ������ڼ��㣩
		void setWinSize(Math::vec2 size);
		Math::vec2 getWinSize();

		~SDL2_Utils();
	private:
		SDL2_Utils();
	private:
		static SDL2_Utils *m_Utils;
		Math::vec2 m_WinSize;
	};
}

#endif // !_SDL2_UTILS_H_BOX