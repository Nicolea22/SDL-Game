#include "GameObjectFactory.h"
#include "Player.h"

class PlayerCreator : public BaseCreator 
{
	GameObject* create_game_object() const 
	{
		return new Player();
	}
};