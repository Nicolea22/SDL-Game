#include "GameOverState.h"
#include "AnimatedGraphics.h"
#include "TextureManager.h"
#include "Parameters.h"
#include "Game.h"

const std::string GameOverState::s_gameover_id = "GAMEOVER";

GameOverState::GameOverState() {}

void GameOverState::update() 
{
	for (int i = 0; i < m_game_objects.size(); i++) 
	{
		m_game_objects[i]->update();
	}
}

void GameOverState::render() 
{
	for (int i = 0; i < m_game_objects.size(); i++)
	{
		m_game_objects[i]->draw();
	}
}

bool GameOverState::on_enter() 
{

	if (!TheTextureManager::Instance()->load("gameover.png","gameover", TheGame::Instance()->get_renderer())) 
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("resume.png", "resumenbutton", TheGame::Instance()->get_renderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("restart.png", "restartbutton", TheGame::Instance()->get_renderer()))
	{
		return false;
	}

	AnimatedGraphics* game_over = new AnimatedGraphics(new Parameters(200, 100, 190, 30, "gameover", 2, 0), 2);

	return true;
}

bool GameOverState::on_exit() 
{
	return true;
}