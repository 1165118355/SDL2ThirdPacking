//	this class is a Action in SDL2. a longggggggggggggg. no write
//	这个动作类一般用于MaterialAnimal，用来控制帧，和图片的切换，达到动画的效果
//	《动作类》
//	2018年7月29日 09:50:14
//	by	水华宝箱

#pragma once
#include <SDL2_Math.h>
#include <SDL2/SDL.h>
#include <SDL2_MaterialPicture.h>
#include <string>


namespace WaterBox
{
	class SDL2_Action
	{
	public:
		///	\brief	创建一个新的动作
		///	
		///	\pragma	pos		动作在图片中的初始位置
		///	\pragma	size	动作在图片中裁剪的尺寸
		///	\pragma	isize	动作在图片中的偏移尺寸
		///	\pragma	number	动作的帧数（一共多少张画）
		static SDL2_Action *create(std::string path, Math::vec2 pos, Math::vec2 size, Math::vec2 isize, int number);

		///	\brief	显示动画的某一帧
		void paly();

		///	\brief	设置动作名字
		void setName(std::string name);
		std::string getName();

		///	\brief	设置路径
		void setPath(std::string path);
		std::string getPath();

		///	\brief	设置动作在图片里面初始的位置
		void setInitPosition(Math::vec2 pos);
		Math::vec2 getInitPosition();

		///	\brief	设置动作在图片里面初始裁剪的大小
		void setCutSize(Math::vec2 size);
		Math::vec2 getCutSize();

		///	\brief	设置动作每帧在图片中的偏移大小
		void setIncreasingSize(Math::vec2 size);
		Math::vec2 getIncreasingSize();

		///	\brief	设置动作的最大帧数（一共有多少张图片可以切换）
		void setMaxFrame(int number);
		int getMaxFrame();

		///	\brief	设置动作速率
		void setVelocity(int velocity);
		int getVelocity();

		void setPosition(Math::vec2 position);
		Math::vec2 getPosition();

		void setSize(Math::vec2 size);
		Math::vec2 getSize();

		SDL2_Material *getMaterial();
	private:
		std::string m_Name;			//	动作名字（）
		SDL2_MaterialPicture *m_Mat;//	存储图片
		std::string m_Path;			//	存储图片的路径
		Math::vec2 m_NowSize;		//	动作目前在图片中裁剪的尺寸
		Math::vec2 m_NowPos;		//	动作目前在图片中的位置

		Math::vec2 m_InitPos;		//	动作初始的位置
		Math::vec2 m_CutSize;		//	动作裁剪图片的尺寸
		Math::vec2 m_IncreasingSize;//	动作在图中切换图片时偏移位置的尺寸

		int m_Action;				//	动作目前在图片中的帧数，（目前是第几帧）
		int m_MaxFrame;				//	动作的最大帧数（一共有多少张图片可以切换）
		int m_Velocity;				//	决定动作切换的速度

	private:
		SDL2_Action();
		~SDL2_Action();

	};
}

