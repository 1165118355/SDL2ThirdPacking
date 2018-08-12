///////////////////////////////
//	this class is a Image in SDL2 
//	UI图像类
//	2018年6月9日 08:18:50
//	by	水华宝箱

#ifndef _SDL2_IMAGE_H_BOX
#define _SDL2_IMAGE_H_BOX

#include <SDL2_Component.h>
#include <SDL2_Material.h>
#include <SDL2/SDL.h>

namespace WaterBox
{
	class SDL2_Image:public SDL2_Component
	{
	public:
		///	brief	创建一个带有图片的GuiImage，参数1是图片路径
		static SDL2_Image *create(std::string path);

		///	brief	创建一个带有图片的GuiImage，参数1是材质
		static SDL2_Image *create(SDL2_Material *mat);

		///	brief	显示该UI
		virtual void show();

		///	brief	更新该UI
		virtual void update(SDL_Event *event);

		/// brief	设置image位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		/// brief	设置image尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	设置该GuiImage的材质（图像在材质中）
		void setMaterial(SDL2_Material *mat);
		SDL2_Material *getMaterial();

		///	brief	设置图像透明度
		virtual void setTransparent(int transparent);
		virtual int getTransparent();

	private:
		SDL2_Image(SDL2_Material *mat);

	private:
		SDL2_Material *m_Material;
	};
}

#endif// !_SDL2_IMAGE_H_BOX