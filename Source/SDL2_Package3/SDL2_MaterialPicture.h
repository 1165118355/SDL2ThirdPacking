///////////////////////////////
//	this class is a Picture in SDL2. use the class ,save the Picture
//	材质，可以存储图片
//	《图片材质类》
//	2018年6月23日 23:58:53
//	by	水华宝箱

#pragma once
#include <string>
#include <SDL2_Math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2_Renderer.h>
#include <SDL2_Material.h>
namespace WaterBox
{
	class SDL2_MaterialPicture :public SDL2_Material
	{
	public:
		///	\brief	将父类强制转换成这个类
		static SDL2_MaterialPicture *cast(SDL2_Material *mat);

		///	brief	创建一个图片材质，更具提供的路径
		static SDL2_MaterialPicture *create();

		///	brief	创建一个图片材质，更具提供的路径
		static SDL2_MaterialPicture *create(std::string path);


		///	brief	显示图片的函数
		virtual void show();

		///	\brief	设置材质的透明度
		virtual void setTransparent(int transparent);
		virtual int getTransparent();

		///	\brief	设置图片的路径
		virtual int setPath(std::string path);
		virtual std::string getPath();

		///	\brief	加载一个xml
		virtual int load(SDL2_Xml *xml);
		virtual SDL2_Xml *save();

		///	\brief	重新加载这个材质（一般用于多窗口渲染时用到）
		virtual void reload();
	private:
		SDL2_MaterialPicture();

	private:
		std::string m_Path;					//	纹理图片的路径
		SDL_Texture *m_Texture;				//	SDL的纹理
	};
}

/*
xml解释
	tag
		name=""					//	
		picture_path=""			//	存储图片的路径

*/