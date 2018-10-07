#include "SDL2_Player.h"
#include <SDL2_MainWindow.h>

using namespace WaterBox;

SDL2_Player * WaterBox::SDL2_Player::create()
{
	SDL2_Player *player = new SDL2_Player();
	return player;
}

void WaterBox::SDL2_Player::setFov(Math::vec2 fov)
{
	m_Fov = fov;
}

Math::vec2 WaterBox::SDL2_Player::getFov()
{
	return m_Fov;
}

void WaterBox::SDL2_Player::setDistance(float distance)
{
	m_Distance = distance;
}

float WaterBox::SDL2_Player::getDistance()
{
	return m_Distance;
}

SDL2_Player::SDL2_Player()
{
	m_Distance = 1.0f;
	m_Fov = SDL2_MainWindow::get()->getSize();
}
