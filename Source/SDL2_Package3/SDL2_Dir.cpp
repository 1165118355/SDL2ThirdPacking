#include "SDL2_Dir.h"
#include <direct.h>
#include <io.h>
#pragma warning(disable:4996)

SDL2_Dir::SDL2_Dir()
{
}

SDL2_Dir * SDL2_Dir::create(std::string path)
{
	SDL2_Dir *dir = new SDL2_Dir();
	dir->setPath(path);
	return dir;
}

void SDL2_Dir::updateDirInfo()
{
	// 更新目录信息
	m_Directories.clear();
	_finddata_t folder;
	int floderNext, floderID = _findfirst((m_Path+"*").c_str(), &folder);
	while (true)
	{
		if (folder.attrib == _A_SUBDIR | _A_HIDDEN && (strcmp(".", folder.name) != 0 && strcmp("..", folder.name) != 0))
		{
			m_Directories.push_back(folder.name);
		}
		floderNext = _findnext(floderID, &folder);
		if (-1 == floderNext)
		{
			break;
		}
	}

	//	更新文件信息
	m_Files.clear();
	_finddata_t files;
	int filesNext, filesID = _findfirst((m_Path + "*.*").c_str(), &files);
	while (true)
	{
		if (files.attrib == _A_ARCH)
		{
			m_Files.push_back(files.name);
		}
		filesNext = _findnext(filesID, &files);
		if (-1 == filesNext)
		{
			break;
		}
	}
}

int SDL2_Dir::setPath(std::string path)
{
	if (-1 == _access(path.c_str(), 0))
	{
		return -1;
	}
	m_Path = path;
	if (m_Path[m_Path.size()] == '/' || m_Path[m_Path.size()] == '\\')
	{
		return 0;
	}
	m_Path += "/";
}

std::string SDL2_Dir::getPath()
{
	return m_Path;
}

int SDL2_Dir::getNumDirectory()
{
	updateDirInfo();
	return m_Directories.size();;
}

std::string SDL2_Dir::getDirectoryName(int num)
{
	updateDirInfo();
	if (m_Directories.size() <= num)
	{
		return std::string("");
	}
	return m_Directories[num];
}

int SDL2_Dir::getNumFile()
{
	updateDirInfo();
	return m_Files.size();
}

std::string SDL2_Dir::getFileName(int num)
{
	updateDirInfo();
	if (m_Files.size() <= num)
	{
		return std::string("");
	}
	return m_Files[num];
}

void SDL2_Dir::createDirectory(std::string name)
{
	mkdir((m_Path + name).c_str());
}

SDL2_Dir::~SDL2_Dir()
{
}
