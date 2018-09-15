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

		///	\����һ����xml�洢��ʽ��Material��
		int loadMaterialLib(std::string matLibPath);

		///	\����һ����xml�洢��ʽ��Material��
		int loadMaterialLib(SDL2_Xml *matLibXml);

		///	\���һ�����ʿ�
		int addMaterial(SDL2_MaterialLibrary *matLib);

		///	\���һ�����ʵ�ָ���Ŀ�
		int addMaterial(SDL2_Material *mat, std::string libName = "default");

		///	\�Ƴ�һ��������ָ���Ŀ�
		int removeMaterial(SDL2_Material *mat, std::string libName = "default");

		///	\brief	����һ�����ʣ�ͨ������
		SDL2_Material *findMaterial(std::string name);

		///	\brief	����һ�����ʣ�ͨ�����ʿ�Ͳ�������
		SDL2_Material *findMaterial(std::string materialName, std::string libName);

		/// \brief	����һ�����ʣ�ͨ��ID
		SDL2_Material *findMaterial(int id);

		///	\brief	��ȡ���ʿ������
		std::string getMaterialLibName(int num);

		///	\brief	��ȡ���ʿ������
		std::string getMaterialLibPath(int num);

		///	\brief	��ȡ���ʿ������
		int getNumMaterialLibs();

		///	\brief	��ȡ���ʿ��в��ʵ�����
		int getNumMaterialByLib(std::string libName);

		///	\brief	�������еĲ��ʿ�
		void save();

		///	\brief	����һ�����ʿ�
		int load(std::string libPath);

		///	\brief	����һ�����ʿ�
		int load(SDL2_Xml *lib);

		///	\brief	����ָ�����ʿ�
		int saveMaterialLib(std::string libName);

		///	\brief	����ָ�����ʿ⵽ָ��λ��
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