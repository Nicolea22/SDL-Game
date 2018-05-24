#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "Parameters.h"

const string MenuState::s_menu_id = "MENU";

void MenuState::update() 
{
	for (int i = 0; i < m_game_objects.size(); i++) 
	{
		m_game_objects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_game_objects.size(); i++)
	{
		m_game_objects[i]->draw();
	}
}

bool MenuState::on_enter()
{
	if (!TheTextureManager::Instance()->load("assets/button.png", "playButton", TheGame::Instance()->get_renderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/exit.png", "exitButton", TheGame::Instance()->get_renderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new Parameters(100, 100, 400, 100, "playButton"));
	GameObject* button2 = new MenuButton(new Parameters(300, 100, 400, 100, "exitButton"));

	m_game_objects.push_back(button1);
	m_game_objects.push_back(button2);

	return true;
}

bool MenuState::on_exit()
{
	return true;
}
