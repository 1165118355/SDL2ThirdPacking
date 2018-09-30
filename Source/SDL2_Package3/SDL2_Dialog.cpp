#include "SDL2_Dialog.h"
#include <SDL2_Renderer.h>

using namespace WaterBox;

SDL2_Dialog::SDL2_Dialog()
{
	m_ComponentType = COMPONENT_DIALOG;
	m_Win = nullptr;
	m_Rend = nullptr;
	m_Win = SDL_CreateWindow("dialog", 110, 110, 500, 500, 0);
	m_Rend = SDL_CreateRenderer(m_Win, -1, 1);
	SDL_SetRenderDrawBlendMode(m_Rend, SDL_BLENDMODE_BLEND);//			设置渲染混合模式（添加透明度渲染）
	/*if (-1 == SDL_CreateWindowAndRenderer(500, 500, 0, &m_Win, &m_Rend))
	{
		SDL_Log("Dialog Create Window error!\n");
	}*/
}

//void WaterBox::SDL2_Dialog::SDL2_DialogMessageBox(std::string title, std::string text)
//{
//	const SDL_MessageBoxButtonData buttons[] = {
//		{ /* .flags, .buttonid, .text */        0, 0, "no" },
//		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "yes" },
//		{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "cancel" },
//	};
//	const SDL_MessageBoxColorScheme colorScheme = {
//		{ /* .colors (.r, .g, .b) */
//		  /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
//			{ 255,   0,   0 },
//			/* [SDL_MESSAGEBOX_COLOR_TEXT] */
//			{ 0, 255,   0 },
//			/* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
//			{ 255, 255,   0 },
//			/* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
//			{ 0,   0, 255 },
//			/* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
//			{ 255,   0, 255 }
//		}
//	};
//	const SDL_MessageBoxData messageboxdata = {
//		SDL_MESSAGEBOX_INFORMATION, /* .flags */
//		NULL, /* .window */
//		"example message box", /* .title */
//		"select a button", /* .message */
//		SDL_arraysize(buttons), /* .numbuttons */
//		buttons, /* .buttons */
//		&colorScheme /* .colorScheme */
//	};
//	int buttonid;
//	if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
//		SDL_Log("error displaying message box");
//	}
//	if (buttonid == -1) {
//		SDL_Log("no selection");
//	}
//	else {
//		SDL_Log("selection was %s", buttons[buttonid].text);
//	}
//}

void WaterBox::SDL2_Dialog::SDL2_DialogBox(DialogBoxType type, std::string title, std::string text)
{
	SDL_ShowSimpleMessageBox(type, title.c_str(), text.c_str(), NULL);
}

SDL2_Dialog * SDL2_Dialog::create()
{
	SDL2_Dialog *dialog = new SDL2_Dialog();
	return dialog;
}

SDL2_Dialog::~SDL2_Dialog()
{
}

void WaterBox::SDL2_Dialog::addComponent(SDL2_Component * component)
{
	m_Components.push_back(component);
}

void WaterBox::SDL2_Dialog::show()
{
	Math::vec4 color(255, 0, 0, 255);
	Math::vec2 position(0, 0);
	Math::vec2 size(500, 500);

	SDL2_Renderer::get()->setRenderer(m_Rend);
	reloadMaterialOfComponent(this);
	SDL_Rect rect = { position.x, position.y, size.x, size.y };
	SDL_SetRenderDrawColor(m_Rend, color.x, color.y, color.z, color.w);
	SDL_RenderFillRect(m_Rend, &rect);

	for (auto &i : m_Components)
	{
		i->show();
	}

	SDL_RenderPresent(m_Rend);
	SDL2_Renderer::get()->backMainRenderer();
	reloadMaterialOfComponent(this);
	
}

void WaterBox::SDL2_Dialog::reloadMaterialOfComponent(SDL2_Component *component)
{
	//	如果是box类型的组件就去遍历box下的所有组件
	if (component->getComponentType() >= COMPONENT_BOX_BEGINE && 
		component->getComponentType() <= COMPONENT_BOX_END)
	{
		for (int i=0; i<SDL2_Box::cast(component)->getNumComponents(); ++i)
		{
			reloadMaterialOfComponent(SDL2_Box::cast(component)->getComponent(i));
		}
		return;
	}
	for (int i=0; i<component->getNumChildes(); ++i)
	{
		reloadMaterialOfComponent(component->getChild(i));
	}

	//	不是box类型的组件就重新加载自己所属的材质
	std::vector<SDL2_Material *> materials = component->getMaterials();
	for (int j = 0; j < materials.size(); ++j)
	{
		materials[j]->reload();
	}
}

void WaterBox::SDL2_Dialog::update(SDL_Event *event)
{
	for (auto &i : m_Components)
	{
		i->update(event);
	}
}
