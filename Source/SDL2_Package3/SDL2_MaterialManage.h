#ifndef _SDL2_MATERIALMANAGE_H_BOX
#define _SDL2_MATERIALMANAGE_H_BOX

#include <SDL2_Xml.h>
#include <SDL2_Math.h>
#include <SDL2_Material.h>
#include <SDL2_MaterialLibrary.h>

namespace WaterBox
{
	class SDL2_MaterialManage
	{
	public:
		static SDL2_MaterialManage *create();
		~SDL2_MaterialManage();

		///	\加载一个以xml存储形式的Material库
		int loadMaterialLib(std::string matLibPath);

		///	\加载一个以xml存储形式的Material库
		int loadMaterialLib(SDL2_Xml *matLibXml);

		///	\添加一个材质库
		int addMaterial(SDL2_MaterialLibrary *matLib);

		///	\添加一个材质到指定的库
		int addMaterial(SDL2_Material *mat, std::string libName = "default");

		///	\移除一个材质在指定的库
		int removeMaterial(SDL2_Material *mat, std::string libName = "default");

		///	\brief	查找一个材质，通过名字
		SDL2_Material *findMaterial(std::string name);

		///	\brief	查找一个材质，通过材质库和材质名字
		SDL2_Material *findMaterial(std::string materialName, std::string libName);

		/// \brief	查找一个材质，通过ID
		SDL2_Material *findMaterial(int id);

		///	\brief	获取材质库的数量
		std::string getMaterialLibName(int num);

		///	\brief	获取材质库的数量
		std::string getMaterialLibPath(int num);

		///	\brief	获取材质库的数量
		int getNumMaterialLibs();

		///	\brief	获取材质库中材质的数量
		int getNumMaterialByLib(std::string libName);

		///	\brief	保存所有的材质库
		void save();

		///	\brief	加载一个材质库
		int load(std::string libPath);

		///	\brief	加载一个材质库
		int load(SDL2_Xml *lib);

		///	\brief	保存指定材质库
		int saveMaterialLib(std::string libName);

		///	\brief	保存指定材质库到指定位置
		int saveMaterialLibAs(std::string libName, std::string targetPath);

		//void 
	private:
		SDL2_MaterialManage();
	private:
		//std::map<std::string, std::vector<SDL2_Material *>> m_MaterialLibs;
		std::vector<SDL2_MaterialLibrary *> m_MaterialLibs;

	};
}

#endif // !_SDL2_MATERIALMANAGE_H_BOX