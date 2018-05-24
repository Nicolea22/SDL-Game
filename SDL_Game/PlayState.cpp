#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Parameters.h"
#include "Player.h"

const string PlayState::s_play_id = "PLAY";

void PlayState::update()
{
	for (int i = 0; i < m_game_objects.size(); i++) 
	{
		m_game_objects[i]->update();
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_game_objects.size(); i++)
	{
		m_game_objects[i]->draw();
	}
}

bool PlayState::on_enter()
{
	
	if (!TheTextureManager::Instance()->load("assets/helicopter.png", "helicopter", TheGame::Instance()->get_renderer())) 
	{
		return false;
	}

	GameObject* player = new Player(new Parameters(100, 100, 128, 52, "helicopter"));

	m_game_objects.push_back(player);

	return true;
}

bool PlayState::on_exit()
{
	for (int i = 0; i < m_game_objects.size(); i++) 
	{
		m_game_objects[i]->clean();
	}

	m_game_objects.clear();

	TheTextureManager::Instance()->clear_from_texture_map("helicopter");

	return true;
}