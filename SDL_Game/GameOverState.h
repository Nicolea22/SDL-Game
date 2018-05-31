#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"

class GameOverState : public GameState
{

public:

	GameOverState();
	~GameOverState() {}

	virtual void update();
	virtual void render();

	virtual bool on_enter();
	virtual bool on_exit();

	virtual std::string get_state_id() const { return s_gameover_id; }

private:

	static const std::string s_gameover_id;

	std::vector<GameObject*> m_game_objects;

	// call back functions for menu items
	static void s_to_main_menu();
	static void s_to_play();
};