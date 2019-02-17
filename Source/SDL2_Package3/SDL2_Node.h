///////////////////////////////
//	this class is a Node in SDL2.
//	表示一个物体，他是很多物体的基类
//	《节点类》
//	2018年8月13日 20:08:34
//	by	水华宝箱
#ifndef _SDL2_NODE_H_BOX
#define _SDL2_NODE_H_BOX

#include <string>
#include <SDL2_Math.h>
#include <SDL2/SDL.h>

namespace WaterBox
{
	class SDL2_Node
	{
	public:
		///	brief	析构走一波
		virtual ~SDL2_Node();

		/// brief	设置位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();
		
		///	brief	设置尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	设置名字
		virtual void setName(std::string name);
		virtual std::string getName();

		///	\brief	获取该Node的id
		virtual int getId();

		///	\brief	更新事件
		virtual void updateEvent(SDL_Event *event);

		///	\brief	更新鼠标事件
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	更新键盘事件
		virtual void updateEventKeyboard(SDL_Event *event);

	protected:
		SDL2_Node();
	protected:
		Math::vec2 m_Position;
		Math::vec2 m_Size;
		std::string m_Name;
		int m_Id;
		SDL2_Node *m_Self;
	};
}

#endif // !_SDL2_NODE_H_BOX