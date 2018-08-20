///////////////////////////////
//	this class is a ui in SDL2.
//	UI类，用于直接加载规范的ui文件
//	《UI类》
//	2018年8月13日 20:12:22
//	by	水华宝箱

#pragma once
#include <SDL2_Xml.h>
#include <SDL2_Component.h>
#include <SDL2_Button.h>
#include <vector>

namespace WaterBox
{
	class SDL2_UserInterface
	{
	public:
		static SDL2_UserInterface *create(std::string path);
		~SDL2_UserInterface();

		///	brief	加载一个ui文件
		int load(std::string path);

		//
		SDL2_Component *findComponent(std::string name);

	private:
		SDL2_UserInterface();

		int componentTypeSwitch(std::string sType);

		//	创建一个组件（根据xml）
		void createComponent(SDL2_Xml *xmlNode, SDL2_Component *parent);
	private:
		std::vector<SDL2_Component *> m_Components;
	};
}

