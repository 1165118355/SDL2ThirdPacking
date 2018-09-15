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
		static SDL2_MaterialLibrary *create();
		static SDL2_MaterialLibrary *create(std::string name);

		///	\brief	设置名字
		void setName(std::string name);
		std::string getName();

		///	\brief	设置路径
		void setPath(std::string path);
		std::string getPath();

		///	\brief	添加一个材质
		int addMaterial(SDL2_Material *mat);

		///	\brief	移除一个材质
		int removeMaterial(SDL2_Material *mat);

		///	\brief	获取材质库的material总数
		int getNumMaterials();

		///	\brief 查找材质
		SDL2_Material *findMaterial(std::string name);

		///	\brief	加载一个库
		int load(std::string path);

		///	\brief	加载一个库
		int load(SDL2_Xml *matLibXml);

		///	\brief	将库保存
		void save();

		~SDL2_MaterialLibrary();
	private:
		SDL2_MaterialLibrary();


	private:
		std::string m_LibName;
		std::string m_LibPath;
		SDL2_Xml *m_MatLibXml;
		std::vector<SDL2_Material *> m_Materials;
	};
}

#endif // !_SDL2_MATERIALLIBRARY_H_BOX

/*

xml 解释

tag
	path="xx/yy"		//	存储这个库的路径
	name="uuu"			//	存储这个库的名字

*/