#pragma once
#include <string>
#include <vector>
#include "GameState.h"
#include "GameObject.h"

class PauseState : public GameState
{
public:

	PauseState() {}
	~PauseState() {}

	virtual void update();
	virtual void render();

	virtual bool on_enter();
	virtual bool on_exit();

	virtual std::string get_state_id() const { return s_pause_id; }

private:

	static const std::string s_pause_id;

	std::vector<GameObject*> m_game_objects;

	// call back functions for menu items
	static void s_resume_game();
	static void s_to_main_menu();

};