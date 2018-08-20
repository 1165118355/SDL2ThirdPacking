#include "SDL2_MaterialAnimal.h"

using namespace WaterBox;

SDL2_MaterialAnimal * WaterBox::SDL2_MaterialAnimal::create()
{
	SDL2_MaterialAnimal *matAnimal = new SDL2_MaterialAnimal();
	return matAnimal;
}

SDL2_MaterialAnimal * WaterBox::SDL2_MaterialAnimal::create(SDL2_MaterialAnimal * mat)
{
	SDL2_MaterialAnimal *matAnimal = new SDL2_MaterialAnimal();
	return matAnimal;
}

void WaterBox::SDL2_MaterialAnimal::addAction(SDL2_Action * action)
{
	m_Actions.push_back(action);
}

void WaterBox::SDL2_MaterialAnimal::show()
{
	play();
}

void WaterBox::SDL2_MaterialAnimal::play(int action)
{
	if (action == 0)
	{
		for (int i=0; i<m_Actions.size(); ++i)
		{
			m_Actions[i]->paly();
		}
	}
	else
	{
		if (action > m_Actions.size())
		{
			return;
		}
		m_Actions[action]->paly();
	}
}

void WaterBox::SDL2_MaterialAnimal::pause(int action)
{
}

void WaterBox::SDL2_MaterialAnimal::stop(int action)
{
}

void WaterBox::SDL2_MaterialAnimal::setLoop(int loop)
{
}

void WaterBox::SDL2_MaterialAnimal::setPosition(Math::vec2 position)
{
	for (int i=0; i<m_Actions.size(); ++i)
	{
		m_Actions[i]->setPosition(position);
	}
}

void WaterBox::SDL2_MaterialAnimal::setSize(Math::vec2 size)
{
	for (int i = 0; i<m_Actions.size(); ++i)
	{
		m_Actions[i]->setSize(size);
	}
}

SDL2_MaterialAnimal::SDL2_MaterialAnimal()
{
}


SDL2_MaterialAnimal::~SDL2_MaterialAnimal()
{
}
