#include "GameState.h"
#include <vector>

class GameStateMachine 
{

public:

	void update();
	void render();

	void push_state(GameState* p_state);
	void change_state(GameState* p_state);
	void pop_state();

private:

	vector<GameState*> m_game_states;

};