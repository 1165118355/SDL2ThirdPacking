#pragma once
#include <SDL2_Math.h>
#include <SDL2_Material.h>
#include<vector>

namespace WaterBox
{
	class SDL2_Materials
	{
	public:
		virtual ~SDL2_Materials();

		/// \brief	œ‘ æ∏√≤ƒ÷ 
		void show();

		void addMaterial(SDL2_Material *mat);

		int removeMaterial(SDL2_Material *mat);

		void clear();

	private:
		SDL2_Materials();
	private:
		std::vector<SDL2_Material *> m_Materials;

	};
}