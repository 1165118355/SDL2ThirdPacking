///////////////////////////////
//	this class is a Player in SDL2.
//	�������������ʾ������
//	������ࡷ
//	2018��8��13�� 20:10:15
//	by	ˮ������

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