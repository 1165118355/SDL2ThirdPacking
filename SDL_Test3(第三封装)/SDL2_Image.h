///////////////////////////////
//	this class is a Image in SDL2 
//	图像类
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
		///	创建一个GuiImage单色彩的
		static SDL2_Image *create();

		///	创建一个带有图片的GuiImage，参数1是图片路径
		static SDL2_Image *create(std::string path);

		///	创建一个带有图片的GuiImage，参数1是材质
		static SDL2_Image *create(SDL2_Material *mat);

		///	显示该UI
		virtual int show();

		///	设置该GuiImage的材质（图像在材质中）
		void setMaterial(SDL2_Material *mat);
		SDL2_Material *getMaterial();
	protected:

	private:
		SDL2_Image(SDL2_Material *mat);
	private:
		SDL2_Material *m_Material;
	};
}

#endif// !_SDL2_IMAGE_H_BOX