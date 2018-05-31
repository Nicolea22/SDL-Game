#pragma once
#include <iostream>
#include <vector>
#include "tinyxml.h"

class GameObject;

class StateParser 
{
public:

	bool parse_state(const char* state_file, std::string stateID, 
		             std::vector<GameObject*>* p_objects, std::vector<std::string>* p_texturesIDs);

private:

	void parse_objects(TiXmlElement* p_state_root, std::vector<GameObject*>* p_objects);
	void parse_textures(TiXmlElement* p_state_root, std::vector<std::string>* p_texture_ids, 
					    std::vector<std::string>* p_textureIDs);

};