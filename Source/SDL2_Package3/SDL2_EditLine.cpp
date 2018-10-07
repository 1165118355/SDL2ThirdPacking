#include "SDL2_EditLine.h"
#include <SDL2_Draw.h>
#include <SDL2_Console.h>
#include <SDL2_System.h>

using namespace WaterBox;

SDL2_EditLine * WaterBox::SDL2_EditLine::create()
{
	SDL2_EditLine *editLine = new SDL2_EditLine();
	return editLine;
}

int WaterBox::SDL2_EditLine::analysisXml(SDL2_Xml * xml)
{
	SDL2_MaterialManage *matManage = SDL2_System::get()->getSceneManager()->getScene()->getMaterialManage();
	if (SDL2_Component::analysisXml(xml) == -1)
	{
		return -1;
	}
	if (xml->getTag("text") != "")
	{
		setText(xml->getTag("text"));
	}
	if (xml->getTag("material_back") != "")
	{
		setMaterialBack(matManage->findMaterial(xml->getTag("material_back")));
	}
	return 0;
}

void WaterBox::SDL2_EditLine::show()
{
	//	��ʾ����
	if (nullptr == m_MaterialBack)
	{
		SDL2_Draw::drawRectangle(m_Position, m_Size, m_ColorBack-30);
		SDL2_Draw::drawRectangle(m_Position+1, m_Size-2, m_ColorBack);
	}
	else
	{
		m_MaterialBack->show();
	}

	//	��ʾ���������
	for (int i= m_ShowStartPos; i<m_ShowEndPos; ++i)
	{
		m_ShowText[i]->show();
	}

	//	�����α��λ�ò���ʾ�α�
	static int showCursor = 0;
	showCursor++;
	if (showCursor == 60)
	{
		showCursor = 0;
	}
	if (1 == m_ChooseFlag && showCursor > 30)
	{
		Math::vec2 cursorPos1 = m_Position;
		Math::vec2 cursorPos2 = m_Position;
		cursorPos2.y += m_Size.y;
		int cursorPos=0;
		for (int i=m_ShowStartPos; i<m_CurSorPos; ++i)
		{
			cursorPos += m_ShowText[i]->getSize().x;
		}
		cursorPos2.x += cursorPos + 1;
		cursorPos1.x += cursorPos + 1;
		SDL2_Draw::drawLine(cursorPos1, cursorPos2, m_ColorCursor);
	}
}

void WaterBox::SDL2_EditLine::updateEventMouse(SDL_Event * event)
{
	int x = event->motion.x;
	int y = event->motion.y;
	if (x > m_Position.x && x < m_Position.x + m_Size.x &&
		y > m_Position.y && y < m_Position.y + m_Size.y)
	{
		if (SDL_MOUSEBUTTONDOWN == event->type)
		{
			m_ChooseFlag = 1;
		}
	}
	else if (SDL_MOUSEBUTTONUP == event->type || SDL_MOUSEBUTTONDOWN == event->type)
	{
		m_ChooseFlag = 0;
	}
}

void WaterBox::SDL2_EditLine::updateEventKeyboard(SDL_Event * event)
{
	std::string addStr;
	if (true == m_ChooseFlag)
	{
		switch (event->type)
		{
		case SDL_TEXTINPUT://				��⵽��������
			addStr = event->text.text;
			m_Text.insert(m_CurSorPos, addStr);
			m_ChangeText = true;
			m_CurSorPos += addStr.size();
			break;
		case SDL_KEYDOWN:
			switch (event->key.keysym.sym)//��ȡ���̰���	
			{
			case SDLK_BACKSPACE://			��������˸�
				m_CurSorPos--;
				if (m_CurSorPos >= 0)
				{
					m_Text.erase(m_CurSorPos, 1);
					m_ChangeText = true;
				}
				m_CurSorPos = Math::clmp(m_CurSorPos, 0, m_ShowText.size());
				break;
			case SDLK_LEFT:
				m_CurSorPos--;
				m_CurSorPos = Math::clmp(m_CurSorPos, 0, m_ShowText.size());
				break;
			case SDLK_RIGHT:
				m_CurSorPos++;
				m_CurSorPos = Math::clmp(m_CurSorPos, 0, m_ShowText.size());
				break;
			}
			break;
		}
	}
}

void WaterBox::SDL2_EditLine::setMaterialBack(SDL2_Material * material)
{
	m_MaterialBack = material;
}

SDL2_Material * WaterBox::SDL2_EditLine::getMaterialBack()
{
	return m_MaterialBack;
}

std::vector<SDL2_Material*> WaterBox::SDL2_EditLine::getMaterials()
{
	std::vector<SDL2_Material*> materials;
	if (nullptr != m_MaterialBack)
	{
		materials.push_back(m_MaterialBack);
	}
	return materials;
}

void WaterBox::SDL2_EditLine::setText(std::string text)
{
	m_Text = text;
	m_ChangeText = true;
}

std::string WaterBox::SDL2_EditLine::getText()
{
	return m_Text;
}

void WaterBox::SDL2_EditLine::update(SDL_Event *event)
{
	//	����ı������ݷ����仯�������¼�����ʾ��label
	if (true == m_ChangeText)
	{
		for (int i=0; i<m_ShowText.size(); ++i)
		{
			delete m_ShowText[i];
		}
		m_ShowText.clear();
		for (int i=0; i<m_Text.size(); ++i)
		{
			m_ShowText.push_back(SDL2_Label::create(m_Text.substr(i, 1), m_ColorFont));
		}
		m_ChangeText = false;
	}

	//	����ַ�����ʾ��ʼ��λ��
	while (true)
	{
		if (m_CurSorPos < m_ShowStartPos)
		{
			m_ShowStartPos = m_CurSorPos;
			break;
		}
		int cursorPosX = this->getPosition().x;
		for (int i= m_ShowStartPos; i<m_CurSorPos; ++i)
		{
			cursorPosX += m_ShowText[i]->getSize().x;
		}
		if (cursorPosX > this->getPosition().x + this->getSize().x)
		{
			m_ShowStartPos++;
		}
		else
		{
			break;
		}
	}

	//	����ַ�����ʾ������λ��
	int lengthX=0;
	for (int i=m_ShowStartPos; i<m_ShowText.size(); ++i)
	{
		m_ShowEndPos = i+1;
		lengthX += m_ShowText[i]->getSize().x;
		if (lengthX > this->getSize().x)
		{
			m_ShowEndPos = i;
			break;
		}
	}
	m_ShowStartPos = Math::clmp(m_ShowStartPos, 0, m_ShowText.size());
	m_ShowEndPos = Math::clmp(m_ShowEndPos, 0, m_ShowText.size());

	//	����label��λ��
	Math::vec2 nowPos = this->getPosition();
	for (int i = m_ShowStartPos; i<m_ShowEndPos; ++i)
	{
		m_ShowText[i]->setPosition(nowPos);
		nowPos.x += m_ShowText[i]->getSize().x;
	}
}

void WaterBox::SDL2_EditLine::materialModification()
{
	if (nullptr != m_MaterialBack)
	{
		m_MaterialBack->setPosition(this->getPosition());
		m_MaterialBack->setSize(this->getSize());
	}
	for (auto &i : m_ShowText)
	{
		i->materialModification();
	}
}

void WaterBox::SDL2_EditLine::setColorBackGround(Math::vec4 color)
{
	m_ColorBack = color;
}

Math::vec4 WaterBox::SDL2_EditLine::getColorBackGround()
{
	return m_ColorBack;
}

void WaterBox::SDL2_EditLine::setColorFont(Math::vec4 color)
{
	m_ColorFont = color;
}

Math::vec4 WaterBox::SDL2_EditLine::getColorFont()
{
	return m_ColorFont;
}

void WaterBox::SDL2_EditLine::setColorCursor(Math::vec4 color)
{
	m_ColorCursor = color;
}

Math::vec4 WaterBox::SDL2_EditLine::getColorCursor()
{
	return m_ColorCursor;
}

void WaterBox::SDL2_EditLine::clear()
{
	for (int i=0; i<m_ShowText.size(); ++i)
	{
		delete m_ShowText[i];
	}
	m_ShowText.clear();
	m_Text.clear();
	m_CurSorPos = 0;
}

WaterBox::SDL2_EditLine::SDL2_EditLine()
{
	m_ColorBack = Math::vec4(Math::vec4(100, 100, 100, 200));
	m_ColorFont =  Math::vec4(Math::vec4(190, 190, 190, 255));
	m_ColorCursor = Math::vec4(Math::vec4(0, 0, 0, 255));
	m_MaterialBack = nullptr;
	m_ChooseFlag = 0;
	m_CurSorPos = 0;
	m_ShowStartPos = m_ShowEndPos = 0;
	setSize(Math::vec2(100, 30));
	setPosition(Math::vec2(0, 0));
	m_ComponentType = COMPONENT_EDITLINE;
	m_ChangeText = false;
}
