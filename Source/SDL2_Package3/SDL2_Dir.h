///////////////////////////////
//	this class is a Dirctory in SDL2.
//	��������Ŀ¼
//	��Ŀ¼�ࡷ
//	2018��9��22�� 14:25:02
//	by	ˮ������

#ifndef _SDL2_DIR_H_BOX
#define _SDL2_DIR_H_BOX

#include <string>
#include <vector>

namespace WaterBox
{
	class SDL2_Dir
	{
	public:
		~SDL2_Dir();
		static SDL2_Dir *create(std::string path = "");

		///	\brief	����ϵͳ������ˢ�µ�ǰ��Ŀ¼��Ϣ
		void updateDirInfo();

		///	\brief	����·��
		///	
		///	\parm	path	·��
		///
		///	\return	�ɹ�=0�� ʧ��=-1
		int setPath(std::string path);
		std::string getPath();

		///	\brief	��ȡ��ǰ·����Ŀ¼������
		int getNumDirectory();

		///	\brief	���ݱ�Ż�ȡĿ¼����
		std::string getDirectoryName(int num);

		///	\brief	��ȡ��ǰĿ¼���ļ�������
		int getNumFile();

		///	\brief	���ݱ�Ż�ȡ�ļ�������
		std::string getFileName(int num);

		///	\brief	����һ��Ŀ¼
		void createDirectory(std::string name);
	private:
		SDL2_Dir();
	private:
		std::string m_Path;
		std::vector<std::string> m_Directories;
		std::vector<std::string> m_Files;
	};
}

#endif	//!_SDL2_DIR_H_BOX

