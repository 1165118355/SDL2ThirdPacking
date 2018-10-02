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
		static SDL2_MaterialText *cast(SDL2_Material *material);
		///	brief	创建一个文字材质，更具给出的字符串
		static SDL2_MaterialText *create();

		///	brief	创建一个文字材质，更具给出的字符串
		static SDL2_MaterialText *create(std::string text);

		///	brief	显示文字材质的函数
		virtual void show();

		///	brief	设置显示文本
		void setText(std::string text, Math::vec4 color = Math::vec4(0, 0, 0, 255));
		std::string getText();

		virtual int load(SDL2_Xml *xml);
		virtual SDL2_Xml *save();

		///	\brief	重新加载这个材质（一般用于多窗口渲染时用到）
		virtual void reload();
	private:
		SDL2_MaterialText();

	private:
		Math::vec4 m_Color;						//	字符串的颜色
		std::string m_Text;						//	字符串，这里存储将要显示的字符串
		SDL_Texture *m_Texture;					//	SDL的纹理
	};
}