#include "PauseState.h"
#include "Game.h"
#include "PlayState.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "InputHandler.h"

const string PauseState::s_pause_id = "PAUSE";

void PauseState::update()
{
	for (int i = 0; i < m_game_objects.size(); i++)
	{
		m_game_objects[i]->update();
	}
}

void PauseState::render()
{
	for (int i = 0; i < m_game_objects.size(); i++)
	{
		m_game_objects[i]->draw();
	}
}

bool PauseState::on_enter()
{
	if (!TheTextureManager::Instance()->load("assets/resume.png", "resumeButton", TheGame::Instance()->get_renderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/restart.png", "restartButton", TheGame::Instance()->get_renderer()))
	{
		return false;
	}

	GameObject* resume_button = new MenuButton(s_resume_game);
	resume_button->load(new Parameters(200, 100, 200, 80, "resumeButton", 3));

	GameObject* restart_button = new MenuButton(s_to_main_menu);
	restart_button->load(new Parameters(200, 300, 200, 80, "restartButton", 3));

	m_game_objects.push_back(resume_button);
	m_game_objects.push_back(restart_button);

	cout << "Entering PauseState" << endl;

	return true;
}

bool PauseState::on_exit()
{
	for (int i = 0; i < m_game_objects.size(); i++)
	{
		m_game_objects[i]->clean();
	}

	m_game_objects.clear();

	// delete the textures from the map
	TheTextureManager::Instance()->clear_from_texture_map("resumeButton");
	TheTextureManager::Instance()->clear_from_texture_map("restartButton");

	cout << "Exiting PauseState" << endl;

	return true;
}

void PauseState::s_resume_game()
{
	TheGame::Instance()->get_state_machine()->change_state(new PlayState());
}

void PauseState::s_to_main_menu()
{
	TheGame::Instance()->get_state_machine()->change_state(new MenuState());
}