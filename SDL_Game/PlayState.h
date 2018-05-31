#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include <vector>

class PlayState : public GameState
{
public:

	virtual void update();
	virtual void render();

	virtual bool on_enter();
	virtual bool on_exit();

	bool check_state_collision(SDLGameObject* p1, SDLGameObject* p2);

	virtual string get_state_id() const { return s_play_id; };

private:

	static const std::string s_play_id;
	std::vector<GameObject*> m_game_objects;

	std::vector<SDLGameObject*> heavens;

};