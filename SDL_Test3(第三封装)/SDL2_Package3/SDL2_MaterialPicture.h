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
		///	brief	创建一个图片材质，更具提供的路径
		static SDL2_MaterialPicture *create(std::string path);

		///	brief	显示图片的函数
		virtual void show();

	private:
		SDL2_MaterialPicture(SDL_Texture *tex);

	private:
		SDL_Texture *m_Texture;				//	SDL的纹理
	};
}