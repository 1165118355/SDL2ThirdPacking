///////////////////////////////
//	this class is a Game in SDL2.
//	游戏类，进行帧数限制什么的
//	《游戏类类》
//	2018年10月1日 13:48:00
//	by	水华宝箱

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

	///	\brief	获取上一帧所运行的时间
	float getIFPS();
protected:
	SDL2_Game();
private:
	static SDL2_Game *m_Instance;
	Uint32 m_Time;					//	记录当前的运行时间
	float m_IFPS;					//	记录上一帧到当前帧所运行的时间
	int m_MaxFPS;					//	FPS最大帧的限制
	bool m_isShowFPS;				//	是否显示FPS
};

#endif