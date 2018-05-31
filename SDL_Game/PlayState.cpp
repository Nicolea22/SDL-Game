#include "PlayState.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Parameters.h"
#include "Player.h"
#include "Vector2D.h"

const string PlayState::s_play_id = "PLAY";

void PlayState::update()
{
	if (TheInputHandler::Instance()->is_key_down(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->get_state_machine()->push_state(new PauseState());
	}

	for (int i = 0; i < m_game_objects.size(); i++) 
	{
		m_game_objects[i]->update();
	}

	for (int i = 0; i < heavens.size(); i++)
	{
		heavens[i]->update();

		if(heavens[i]->get_pos().get_comp_x() == -640)
		{
			heavens[i]->set_pos(Vector2D(640, 0));
		}
	}
}

void PlayState::render()
{
	for (int i = 0; i < heavens.size(); i++)
	{
		heavens[i]->draw();
	}

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

	if (!TextureManager::Instance()->load("assets/heaven.jpg", "heaven", TheGame::Instance()->get_renderer())) 
	{
		return false;
	}
	
	if (!TextureManager::Instance()->load("assets/guns.png", "gatling", TheGame::Instance()->get_renderer()))
	{
		return false;
	}
	
	GameObject* player = new Player();
	player->load(new Parameters(100, 100, 128, 55, "helicopter", 4));
	m_game_objects.push_back(player);

	SDLGameObject* heaven1 = new SDLGameObject();
	heaven1->load(new Parameters(0, 0, 640, 480, "heaven", 1));

	SDLGameObject* heaven2 = new SDLGameObject();
	heaven2->load(new Parameters(0, 0, 640, 480, "heaven", 1));

	heavens.push_back(heaven1);
	heavens.push_back(heaven2);

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
	TheTextureManager::Instance()->clear_from_texture_map("heaven");

	return true;
}


bool PlayState::check_state_collision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA   = p1->get_pos().get_comp_x();
	rightA  = p1->get_pos().get_comp_x() + p1->get_width();
	topA    = p1->get_pos().get_comp_y();
	bottomA = p1->get_pos().get_comp_y() + p1->get_height();

	leftB   = p2->get_pos().get_comp_x();
	rightB  = p2->get_pos().get_comp_x() + p2->get_width();
	topB    = p2->get_pos().get_comp_y();
	bottomB = p2->get_pos().get_comp_y() + p2->get_height();

	if (topA <= bottomB) { return false; }
	if (bottomA <= topB) { return false; }
	if (rightA >= leftB) { return false; }
	if (leftA <= rightB) { return false; }

	return true;
}