///////////////////////////////
//	this class is a Material in SDL2. Save the Material use the class please.
//	���ʵ����࣬һ��������������в��ʵĴ洢
//	�����ʿ��ࡷ
//	2018��9��9�� 18:17:02
//	by	ˮ������

#ifndef _SDL2_MATERIALLIBRARY_H_BOX
#define _SDL2_MATERIALLIBRARY_H_BOX

#include <SDL2_Xml.h>
#include <SDL2_Math.h>
#include <SDL2_Material.h>

namespace WaterBox
{
	class SDL2_MaterialLibrary
	{
	public:
		~SDL2_MaterialLibrary();
	private:
		SDL2_MaterialLibrary();


	private:
		std::string m_LibName;
		std::string m_LibPath;
		std::vector<SDL2_Material *> m_Materials;
	};
}

#endif // !_SDL2_MATERIALLIBRARY_H_BOX