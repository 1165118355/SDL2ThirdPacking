///////////////////////////////
//	this class is a Material in SDL2. Save the Material use the class please.
//	材质的总类，一般用这个类来进行材质的存储
//	《材质库类》
//	2018年9月9日 18:17:02
//	by	水华宝箱

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