///////////////////////////////
//	this class is a FontSystem in SDL2.let's find and use the font in the class
//	�����弯�����������ͨ��������������ҵ�����ʹ��ĳ������
//	����ϵͳ��
//	2018��6��23�� 23:53:34
//	by	ˮ������

#pragma once
#include <SDL2/SDL_ttf.h>
#include <map>

namespace WaterBox
{
	class SDL2_FontSystem
	{
	public:
		static SDL2_FontSystem *get();

		///	brief	����һ������
		///	prame	path	�����·��
		///	prame	name	��������֣����ڲ��ң�
		///	prame	size	����ĳߴ�
		TTF_Font *createFont(std::string path, std::string name, int size=20);

		///	brief	Ѱ�Ҳ�����ĳ������
		TTF_Font *findFont(std::string name);

	private:
		SDL2_FontSystem();							//	���캯��

	private:
		std::map<std::string, TTF_Font *> m_Fonts;	//	�������ʹ��map������ͨ��һ���ַ�������������
		static SDL2_FontSystem *m_FontSys;			//	����ʹ�õ���ģʽ
	};
}