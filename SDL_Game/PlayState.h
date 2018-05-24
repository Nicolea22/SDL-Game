#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <vector>

using namespace std;

class PlayState : public GameState
{

public:

	virtual void update();
	virtual void render();

	virtual bool on_enter();
	virtual bool on_exit();

	virtual string get_state_id() const { return s_play_id; };

private:

	static const string s_play_id;
	vector<GameObject*> m_game_objects;

};