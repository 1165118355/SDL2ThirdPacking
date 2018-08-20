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
		///	\brief	普通的创建一个label
		static SDL2_Label *create(std::string text="label");

		///	\brief	通过xml信息创建一个Label
		static SDL2_Label *create(SDL2_Xml *xml);

		///	brief	设置位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2  getPosition();

		///	brief	设置尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		/// \brief	设置文本
		void setText(std::string text);
		std::string getText();

		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	显示
		virtual void show();

		///	brief	更新事件
		virtual void update(SDL_Event *event);
	private:
		SDL2_Label();
	private:
		std::string m_Text;					//	要显示的文本
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