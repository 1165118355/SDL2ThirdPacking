///////////////////////////////
//	this class is a VBox in SDL2.
//	主要用来装下其他组件，是个容器，
//	《组件容器类》
//	2018年7月7日 23:27:29
//	by	水华宝箱
#pragma once
#include <SDL2_Component.h>
#include <vector>

namespace WaterBox
{
	class SDL2_Box :public SDL2_Component
	{
	public:
		virtual ~SDL2_Box();
		static SDL2_Box *cast(SDL2_Component *component);

		///	\brief	用于添加组件在这里
		virtual void addComponent(SDL2_Component *component);

		///	\brief	获取组件的数量
		virtual int getNumComponents();
		virtual SDL2_Component *getComponent(int num);

		///	\brief	材质的位置校正，保证材质显示在物体上的正确位置上，类似3d里面的UV一样
		virtual void materialModification();

		///	\brief	显示
		virtual void show();

		/// \brief	更新事件
		virtual void update(SDL_Event *event);

		///	\brief	清理（删除所有组件）
		virtual void clear();
	protected:
		SDL2_Box();
	protected:
		std::vector<SDL2_Component *> m_Components;
	private:
	};
}