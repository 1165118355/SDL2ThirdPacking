#include "SDL2_Console.h"
#include <SDL2_Event.h>
#include <SDL2_Draw.h>
#include <SDL2_Event.h>
#pragma warning(disable:4996)//  ȥ��4996���棬˵�Ǿ��棬ʵ�����Ǳ���

using namespace WaterBox;

SDL2_Console *SDL2_Console::m_Instance = nullptr;

SDL2_Console * SDL2_Console::get()
{
	if (nullptr == m_Instance)
	{
		m_Instance = new SDL2_Console();
	}
	return m_Instance;
}

void WaterBox::SDL2_Console::update(SDL_Event * event)
{
	Math::vec2 bottomPos = m_Position + m_Size;
	bottomPos.x = 0;
	m_ShowBottomTextNumber = (m_Texts.size()-1.0) / m_Slider->getValueMax()*m_Slider->getValue();
	m_ShowBottomTextNumber = Math::clmp(m_ShowBottomTextNumber, 0, m_Texts.size())-1;
	for (int i = m_ShowBottomTextNumber; i >= 0; --i)
	{
		bottomPos.y -= m_Texts[i]->getSize().y;
		m_Texts[i]->setPosition(bottomPos);
		m_Texts[i]->materialModification();
	}
	m_Slider->update(event);
}

void WaterBox::SDL2_Console::show()
{
	if (false == m_Show)
	{
		if (m_Position.y > -m_Size.y)
		{
			m_Position.y -= 10;
			m_Slider->setPosition(Math::vec2(m_Position.x + m_Size.x - m_Slider->getSize().x, m_Position.y));
		}
	}
	else
	{
		if (m_Position.y < 0)
		{
			m_Position.y += 10;
			m_Slider->setPosition(Math::vec2(m_Position.x + m_Size.x - m_Slider->getSize().x, m_Position.y));
		}
	}
	SDL2_Draw::drawRectangle(m_Position, m_Size, Math::vec4(30, 30, 30, 99));
	for (int i=0; i<=m_ShowBottomTextNumber; ++i)
	{
		m_Texts[i]->show();
	}
	m_Slider->show();
}

void WaterBox::SDL2_Console::updateEventMouse(SDL_Event * event)
{
	m_Slider->updateEventMouse(event);
	if (event->motion.type == SDL_MOUSEBUTTONDOWN)
	{
		m_FocusMouse = SDL2_Event::get()->getMousePosition();
	}
	if (event->wheel.type == SDL_MOUSEWHEEL)
	{
		if (m_FocusMouse.x > m_Position.x && m_FocusMouse.x < m_Position.x + m_Size.x &&
			m_FocusMouse.y > m_Position.y && m_FocusMouse.y < m_Position.y + m_Size.y)
		{
			int add = m_Slider->getValueMax() / m_Texts.size();
			add = Math::clmp(add, 1, m_Slider->getValueMax());
			if (event->wheel.y > 0)
			{
				m_Slider->setValue(m_Slider->getValue() - add);
			}
			else if (event->wheel.y < 0)
			{
				m_Slider->setValue(m_Slider->getValue() + add);
			}
		}
	}
}

void WaterBox::SDL2_Console::updateEventKeyboard(SDL_Event * event)
{
	static bool keyDown = false;
	if (event->type == SDL_KEYDOWN && false == keyDown && event->key.keysym.sym == '`')
	{
		m_Show = !m_Show;
		keyDown = true;
	}
	if (event->type == SDL_KEYUP && event->key.keysym.sym == '`')
	{
		keyDown = false;
	}
}

bool WaterBox::SDL2_Console::run(std::string common)
{
	if (common == "clear")
	{
		this->clear();
	}
	else
	{
		return false;
	}
	return true;
}

void WaterBox::SDL2_Console::addLog(const char * format, ...)
{
	char ch[20];
	std::string text ="";
	va_list ap;      
	va_start(ap, format);     //��apָ���һ��ʵ�ʲ����ĵ�ַ    
	while(*format)      
	{          
		if(*format != '%')
		{             
			sprintf(ch, "%c", *format);
			text += ch;
			format++;          
		}          
		else
		{           
			format++;
			switch(*format) 
			{                  
			case 'c':         
			{                  
				char valch = va_arg(ap,int);  //��¼��ǰʵ���������ڵ�ַ 
				sprintf(ch, "%c", valch);
				text += ch;
				format++;                      
				break;                
			}                 
			case 'd':           
			{                    
				int valint = va_arg(ap,int);  
				sprintf(ch, "%d", valint);
				text += ch;
				format++;                     
				break;                 
			}                 
			case 's':              
			{                     
				char *valstr = va_arg(ap,char *);
				text += valstr;
				format++;                   
				break;                 
			}               
			case 'f':               
			{                    
				float valflt = va_arg(ap,double);
				sprintf(ch, "%f", valflt);
				text += ch;
				format++;                   
				break;                
			}                  
			default:            
			{
				sprintf(ch, "%c", *format);
				text += ch;
				format++;             
			}            
			}         
		}     
	}   
	va_end(ap);
	m_Texts.push_back(SDL2_Label::create(text, Math::vec4(200, 200, 200, 255)));
}

void WaterBox::SDL2_Console::addWarning(const char* format, ...)
{
	char ch[20];
	std::string str = "";
	va_list ap;
	va_start(ap, format);     //��apָ���һ��ʵ�ʲ����ĵ�ַ    
	while (*format)
	{
		if (*format != '%')
		{
			sprintf(ch, "%c", *format);
			str += ch;
			format++;
		}
		else
		{
			format++;
			switch (*format)
			{
			case 'c':
			{
				char valch = va_arg(ap, int);  //��¼��ǰʵ���������ڵ�ַ 
				sprintf(ch, "%c", valch);
				str += ch;
				format++;
				break;
			}
			case 'd':
			{
				int valint = va_arg(ap, int);
				sprintf(ch, "%d", valint);
				str += ch;
				format++;
				break;
			}
			case 's':
			{
				char *valstr = va_arg(ap, char *);
				str += valstr;
				format++;
				break;
			}
			case 'f':
			{
				float valflt = va_arg(ap, double);
				sprintf(ch, "%f", valflt);
				str += ch;
				format++;
				break;
			}
			default:
			{
				sprintf(ch, "%c", *format);
				str += ch;
				format++;
			}
			}
		}
	}
	va_end(ap);
	m_Texts.push_back(SDL2_Label::create(str, Math::vec4(200, 200, 90, 255)));
}

void WaterBox::SDL2_Console::addError(const char* format, ...)
{
	char ch[20];
	std::string text = "";
	va_list ap;
	va_start(ap, format);     //��apָ���һ��ʵ�ʲ����ĵ�ַ    
	while (*format)
	{
		if (*format != '%')
		{
			sprintf(ch, "%c", *format);
			text += ch;
			format++;
		}
		else
		{
			format++;
			switch (*format)
			{
			case 'c':
			{
				char valch = va_arg(ap, int);  //��¼��ǰʵ���������ڵ�ַ 
				sprintf(ch, "%c", valch);
				text += ch;
				format++;
				break;
			}
			case 'd':
			{
				int valint = va_arg(ap, int);
				sprintf(ch, "%d", valint);
				text += ch;
				format++;
				break;
			}
			case 's':
			{
				char *valstr = va_arg(ap, char *);
				text += valstr;
				format++;
				break;
			}
			case 'f':
			{
				float valflt = va_arg(ap, double);
				sprintf(ch, "%f", valflt);
				text += ch;
				format++;
				break;
			}
			default:
			{
				sprintf(ch, "%c", *format);
				text += ch;
				format++;
			}
			}
		}
	}
	va_end(ap);
	m_Texts.push_back(SDL2_Label::create(text, Math::vec4(200, 20, 40, 255)));
}

void WaterBox::SDL2_Console::clear()
{
	for (int i=0; i<m_Texts.size(); ++i)
	{
		delete m_Texts[i];
	}
	m_Texts.clear();
}

void SDL2_Console::setShow(bool show)
{
	m_Show = show;
}

bool SDL2_Console::getShow()
{
	return m_Show;
}

SDL2_Console::SDL2_Console()
{
	m_Show = false;
	Math::vec2 winSize = SDL2_Utils::get()->getWinSize();
	this->setPosition(Math::vec2(0, 0));
	this->setSize(Math::vec2(winSize.x, winSize.y/3*2));
	m_Slider = SDL2_Slider::create(m_Size.y);
	m_Slider->setSliderType(SDL2_Slider::SLIDER_VERTICAL);
	m_Slider->setValueMax(1000);
	m_Slider->setValue(1000);
}


SDL2_Console::~SDL2_Console()
{
}
