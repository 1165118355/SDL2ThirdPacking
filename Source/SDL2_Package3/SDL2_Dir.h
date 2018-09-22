///////////////////////////////
//	this class is a Dirctory in SDL2.
//	用来操作目录
//	《目录类》
//	2018年9月22日 14:25:02
//	by	水华宝箱

#ifndef _SDL2_DIR_H_BOX
#define _SDL2_DIR_H_BOX

#include <string>
#include <vector>

class SDL2_Dir
{
public:
	~SDL2_Dir();
	static SDL2_Dir *create(std::string path = "");

	///	\brief	调用系统函数来刷新当前的目录信息
	void updateDirInfo();

	///	\brief	设置路径
	///	
	///	\parm	path	路径
	///
	///	\return	成功=0， 失败=-1
	int setPath(std::string path);
	std::string getPath();

	///	\brief	获取当前路径下目录的数量
	int getNumDirectory();

	///	\brief	根据编号获取目录名字
	std::string getDirectoryName(int num);

	///	\brief	获取当前目录下文件的数量
	int getNumFile();

	///	\brief	根据编号获取文件的名字
	std::string getFileName(int num);

	///	\brief	创建一个目录
	void createDirectory(std::string name);
private:
	SDL2_Dir();
private:
	std::string m_Path;
	std::vector<std::string> m_Directories;
	std::vector<std::string> m_Files;
};
#endif	//!_SDL2_DIR_H_BOX

