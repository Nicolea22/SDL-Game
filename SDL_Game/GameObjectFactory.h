#pragma once
#include "GameObject.h"
#include <string>
#include <map>

class BaseCreator 
{
	
public:

	virtual GameObject* create_game_object() const = 0;
	virtual ~BaseCreator() {}

};


class GameObjectFactory 
{

public:

	bool register_type(std::string type_id, BaseCreator* creator) 
	{
		std::map<std::string, BaseCreator*>::iterator it = m_creators.find(type_id);

		if (it != m_creators.end()) 
		{
			delete creator;
			return false;
		}
		m_creators[type_id] = creator;
		return true;
	}

	GameObject* create(std::string type_id) 
	{
		std::map<string, BaseCreator*>::iterator it = m_creators.find(type_id);

		if (it == m_creators.end()) 
		{
			std::cout << "Could not find the type" << endl;
			return 0;
		}

		BaseCreator* creator = (*it).second;

		return creator->create_game_object();
	}


private:

	std::map<std::string, BaseCreator*> m_creators;

};