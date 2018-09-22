///////////////////////////////
//	this class is a MaterialAnimal in SDL2. Dynamic Object used The material ,normal
//	动画材质类，一般的动态对象会使用这个材质
//	《材质类》
//	2018年7月29日 09:06:12
//	by	水华宝箱
#pragma once
#include <SDL2_Action.h>
#include <SDL2_Material.h>
#include <vector>

namespace WaterBox
{
	
	class SDL2_MaterialAnimal :public SDL2_Material
	{
	public:
	public:
		///	\brief	创建一个动画材质（）
		static SDL2_MaterialAnimal *create(); 

		///	\brief	直接用材质来初始化这个动画
		static SDL2_MaterialAnimal *create(SDL2_MaterialAnimal *mat);

		void addAction(SDL2_Action *action);

		/// \brief	显示动画
		virtual void show();

		///	\brief	播放（loop==1的话会循环播放）
		///
		///	\pragma	选择播放的动作（默认0，播放所有）
		virtual void play(int action = 0);

		///	\brief	暂停播放
		///	
		///	\pragma	选择暂停播放的动作（默认0，暂停所有）
		virtual void pause(int action = 0);

		///	\brief	重置播放
		///	
		///	\pragma 选择暂停播放的动作（默认0，暂停所有）
		virtual void stop(int action = 0);

		///	\brief	设置循环播放
		virtual void setLoop(int loop);

		///	\brief	设置位置
		virtual void setPosition(Math::vec2 position);

		///	\brief	设置尺寸
		virtual void setSize(Math::vec2 size);

		///	\brief	加载材质
		virtual int load(SDL2_Xml *xml);
		virtual SDL2_Xml *save();

		///	\brief	重新加载这个材质（一般用于多窗口渲染时用到）
		virtual void reload();
	protected:
		SDL2_MaterialAnimal();
		~SDL2_MaterialAnimal();
	private:
		std::vector<SDL2_Action *> m_Actions;
		int m_Action;
		int m_Loop;
	};
}