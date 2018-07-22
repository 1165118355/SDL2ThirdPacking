#include "SDL2_MainWindow.h"

using namespace WaterBox;

SDL2_MainWindow *SDL2_MainWindow::m_MainWindow = nullptr;

SDL2_MainWindow::SDL2_MainWindow()
{
	m_Win = SDL2_Window::create("MainWindow", Math::vec2(0, 0), Math::vec2(500, 500));
}


SDL2_MainWindow * WaterBox::SDL2_MainWindow::get()
{
	if (m_MainWindow == nullptr)
	{
		m_MainWindow = new SDL2_MainWindow();
	}
	return m_MainWindow;
}

SDL2_MainWindow::~SDL2_MainWindow()
{
}

SDL2_Window * WaterBox::SDL2_MainWindow::getSDL2Window()
{
	return m_Win;
}

void WaterBox::SDL2_MainWindow::setPosition(Math::vec2 position)
{
	m_Win->setPosition(position);
}

Math::vec2 WaterBox::SDL2_MainWindow::getPosition()
{
	return m_Win->getPosition();
}

void WaterBox::SDL2_MainWindow::setSize(Math::vec2 size)
{
	m_Win->setSize(size);
}

Math::vec2 WaterBox::SDL2_MainWindow::getSize()
{
	return m_Win->getSize();
}
