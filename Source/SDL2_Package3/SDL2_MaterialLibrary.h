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
		static SDL2_MaterialLibrary *create();
		static SDL2_MaterialLibrary *create(std::string name);

		///	\brief	��������
		void setName(std::string name);
		std::string getName();

		///	\brief	����·��
		void setPath(std::string path);
		std::string getPath();

		///	\brief	���һ������
		int addMaterial(SDL2_Material *mat);

		///	\brief	�Ƴ�һ������
		int removeMaterial(SDL2_Material *mat);

		///	\brief	��ȡ���ʿ��material����
		int getNumMaterials();

		///	\brief ���Ҳ���
		SDL2_Material *findMaterial(std::string name);

		///	\brief	����һ����
		int load(std::string path);

		///	\brief	����һ����
		int load(SDL2_Xml *matLibXml);

		///	\brief	���Ᵽ��
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

xml ����

tag
	path="xx/yy"		//	�洢������·��
	name="uuu"			//	�洢����������

*/