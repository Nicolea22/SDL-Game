#include "MenuState.h"
#include "PlayState.h"
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

	GameObject* button1 = new MenuButton(new Parameters(100, 100, 400, 100, "playButton"), s_menu_to_play);
	GameObject* button2 = new MenuButton(new Parameters(100, 300, 400, 100, "exitButton"), s_exit_from_menu);

	m_game_objects.push_back(button1);
	m_game_objects.push_back(button2);

	cout << "Entering MenuState" << endl;

	return true;
}

bool MenuState::on_exit()
{
	for (int i = 0; i < m_game_objects.size(); i++) 
	{
		m_game_objects[i]->clean();
	}

	m_game_objects.clear();

	// delete the textures from the map
	TheTextureManager::Instance()->clear_from_texture_map("playButton");
	TheTextureManager::Instance()->clear_from_texture_map("exitButton");
	
	cout << "Exiting MenuState" << endl;

	return true;
}

void MenuState::s_menu_to_play()
{
	TheGame::Instance()->get_state_machine()->change_state(new PlayState());
}

void MenuState::s_exit_from_menu()
{
	TheGame::Instance()->quit();
}