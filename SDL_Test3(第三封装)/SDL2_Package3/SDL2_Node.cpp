#include "SDL2_Node.h"
#include <SDL2_IdCreator.h>

using namespace WaterBox;

SDL2_Node::SDL2_Node()
{
	m_Position = Math::vec2();
	m_Size = Math::vec2();
	m_Id = SDL2_IdCreator::get()->createId();
}


void WaterBox::SDL2_Node::setPosition(Math::vec2 position)
{
	m_Position = position;
}

Math::vec2 WaterBox::SDL2_Node::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_Node::setSize(Math::vec2 size)
{
	m_Size = size;
}

Math::vec2 WaterBox::SDL2_Node::getSize()
{
	return m_Size;
}

int WaterBox::SDL2_Node::getId()
{
	return m_Id;
}

SDL2_Node::~SDL2_Node()
{
	SDL2_IdCreator::get()->removeId(m_Id);
}
