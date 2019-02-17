///////////////////////////////
//	this class is a Game in SDL2.
//	��Ϸ�࣬����֡������ʲô��
//	����Ϸ���ࡷ
//	2018��10��1�� 13:48:00
//	by	ˮ������

#ifndef _SDL2_GAME_H_BOX
#define _SDL2_GAME_H_BOX

#include <SDL2/SDL.h>
class SDL2_Game
{
public:
	static SDL2_Game *get();
	~SDL2_Game();

	void init();

	void update();

	///	\brief	��ȡ��һ֡�����е�ʱ��
	float getIFPS();
protected:
	SDL2_Game();
private:
	static SDL2_Game *m_Instance;
	Uint32 m_Time;					//	��¼��ǰ������ʱ��
	float m_IFPS;					//	��¼��һ֡����ǰ֡�����е�ʱ��
	int m_MaxFPS;					//	FPS���֡������
	bool m_isShowFPS;				//	�Ƿ���ʾFPS
};

#endif