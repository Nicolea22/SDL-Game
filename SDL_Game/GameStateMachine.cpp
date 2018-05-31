#include "GameStateMachine.h"
#include "Global.h"
#include <iostream>

using namespace std;

void GameStateMachine::update() 
{
	if(!m_game_states.empty())
	{
		m_game_states.back()->update();
	}
}

void GameStateMachine::render()
{
	if (!m_game_states.empty())
	{
		m_game_states.back()->render();
	}
}

void GameStateMachine::push_state(GameState* p_state) 
{
	m_game_states.push_back(p_state);
	m_game_states.back()->on_enter();
}

void GameStateMachine::pop_state() 
{
	if (!m_game_states.empty()) 
	{
		if (m_game_states.back()->on_exit()) 
		{
			delete m_game_states.back();
			m_game_states.pop_back();
		}
	}
}

void GameStateMachine::change_state(GameState *p_state)
{
	if (!m_game_states.empty())
	{
		if (m_game_states.back()->get_state_id() == p_state->get_state_id())
		{
			return; // do nothing
		}
		if (m_game_states.back()->on_exit())
		{
			delete m_game_states.back();
			m_game_states.pop_back();
		}
	}

	// push back the new state

	m_game_states.push_back(p_state);
	// initialise it
	m_game_states.back()->on_enter();
}