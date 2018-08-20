///////////////////////////////
//	this class is a FontSystem in SDL2.let's find and use the font in the class
//	将字体集中在这里，可以通过字体的名字来找到并且使用某个字体
//	字体系统类
//	2018年6月23日 23:53:34
//	by	水华宝箱

#pragma once
#include <SDL2/SDL_ttf.h>
#include <map>

namespace WaterBox
{
	class SDL2_FontSystem
	{
	public:
		static SDL2_FontSystem *get();

		///	brief	创建一个字体
		///	prame	path	字体的路径
		///	prame	name	字体的名字（用于查找）
		///	prame	size	字体的尺寸
		TTF_Font *createFont(std::string path, std::string name, int size=20);

		///	brief	寻找并返回某个字体
		TTF_Font *findFont(std::string name);

	private:
		SDL2_FontSystem();							//	构造函数

	private:
		std::map<std::string, TTF_Font *> m_Fonts;	//	字体管理使用map来管理，通过一个字符串来查找字体
		static SDL2_FontSystem *m_FontSys;			//	本身使用单例模式
	};
}