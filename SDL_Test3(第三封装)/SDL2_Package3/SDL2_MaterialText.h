///////////////////////////////
//	this class is a Text in SDL2. 
//	材质，可以存储文字（该文字以图片的形式存在）
//	《文字材质类》
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
	class SDL2_MaterialText :public SDL2_Material
	{
	public:
		///	brief	创建一个文字材质，更具给出的字符串
		static SDL2_MaterialText *create(std::string text);

		///	brief	显示文字材质的函数
		virtual void show();

	private:
		SDL2_MaterialText(SDL_Texture *tex, std::string text);

	private:
		std::string m_Text;						//	字符串，这里存储将要显示的字符串
		SDL_Texture *m_Texture;					//	SDL的纹理
	};
}