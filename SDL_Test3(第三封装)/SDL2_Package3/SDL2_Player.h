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
	private:
		SDL2_Player();
	private:

	};
}
#endif //!_SDL2_PLAYER_H_BOX