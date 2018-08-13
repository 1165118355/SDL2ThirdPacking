#include "SDL2_IdCreator.h"
#include <time.h>
#include <stdlib.h>

SDL2_IdCreator *SDL2_IdCreator::m_IdCreator = nullptr;

SDL2_IdCreator * SDL2_IdCreator::get()
{
	if (m_IdCreator == nullptr)
	{
		m_IdCreator = new SDL2_IdCreator();
	}
	return m_IdCreator;
}

int SDL2_IdCreator::createId()
{
	int id;
	while (m_Ids.find(id) != m_Ids.end())
	{
		id = rand();
	}
	m_Ids.insert(id);
	return id;
}

int SDL2_IdCreator::removeId(int id)
{
	if (m_Ids.find(id) == m_Ids.end())
	{
		return -1;
	}
	m_Ids.erase(id);
	return 0;
}

SDL2_IdCreator::SDL2_IdCreator()
{
	srand(time(NULL));
}


SDL2_IdCreator::~SDL2_IdCreator()
{
}
