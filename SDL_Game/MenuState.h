#include "GameState.h"
#include <vector>
#include "GameObject.h"

using namespace std;

class MenuState : public GameState
{

public:

	MenuState() {}
	~MenuState() {}

	virtual void update();
	virtual void render();

	virtual bool on_enter();
	virtual bool on_exit();

	virtual string get_state_id() const { return s_menu_id; }

private:

	static const string s_menu_id;

	vector<GameObject*> m_game_objects;

	// call back functions for menu items
	static void s_menu_to_play();
	static void s_exit_from_menu();

};