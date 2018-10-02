///////////////////////////////
//	this class is a Label in SDL2.
//	标签类主要是显示文字
//	《标签类》
//	2018年6月25日 22:05:19
//	by	水华宝箱
#ifndef _SDL2_LABEL_H_BOX
#define _SDL2_LABEL_H_BOX

#include <string>
#include <SDL2_MaterialText.h>
#include <SDL2_Component.h>
#include <SDL2_Xml.h>

namespace WaterBox 
{
	class SDL2_Label: public SDL2_Component
	{
	public:
		virtual ~SDL2_Label();

		///	\brief	普通的创建一个label
		static SDL2_Label *create(std::string text="label", Math::vec4 color = Math::vec4(0, 0, 0, 255));

		///	\brief	通过xml信息创建一个Label
		static SDL2_Label *create(SDL2_Xml *xml);

		///	brief	设置位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2  getPosition();

		///	brief	设置尺寸（lable设置无效， 请使用setScale()函数）
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	\brief	设置文字大小比例
		void setScale(double scale);
		double getScale();

		/// \brief	设置文本
		void setText(std::string text, Math::vec4 color = Math::vec4(0, 0, 0, 255));
		std::string getText();

		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	更新事件
		virtual void update(SDL_Event *event);

		///	\brief	材质的位置校正，保证材质显示在物体上的正确位置上，类似3d里面的UV一样
		virtual void materialModification();

		///	brief	显示
		virtual void show();

		///	\brief	获取所有的material
		virtual std::vector<SDL2_Material *> getMaterials();

		///	\brief	更新鼠标事件
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	更新键盘事件
		virtual void updateEventKeyboard(SDL_Event *event);
	private:
		SDL2_Label();
	private:
		Math::vec2 m_OriginalTextSize;			//	文本原本的大小
		double m_Scale;							//	文字放大的比例
		std::string m_Text;						//	要显示的文本
		SDL2_MaterialText *m_MaterialText;		//	文本的Material

	};
}
#endif // !_SDL2_LABEL_H_BOX


/*
xml说明
	tag说明
		text=""			//	显示的文字		（仅限图片不能是动画）
	name说明
	<label>				//	名字就是这个咯
*/