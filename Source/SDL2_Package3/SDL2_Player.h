///////////////////////////////
//	this class is a Player in SDL2.
//	相机用来控制显示的区域
//	《相机类》
//	2018年8月13日 20:10:15
//	by	水华宝箱

#ifndef _SDL2_PLAYER_H_BOX
#define _SDL2_PLAYER_H_BOX

#include <SDL2_Node.h>

namespace WaterBox
{
	class SDL2_Player :public SDL2_Node
	{
	public:
		static SDL2_Player *create();

		///	\brief	设置摄像机的可视范围
		void setFov(Math::vec2 fov);
		Math::vec2 getFov();

		///	\brief	设置相机与场景的距离
		void setDistance(float distance);
		float getDistance();
	private:
		SDL2_Player();
	private:
		Math::vec2 m_Fov;		//	相机可视范围
		float m_Distance;			//	相机离地面的距离
	};
}
#endif //!_SDL2_PLAYER_H_BOX