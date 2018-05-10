#pragma once
#include <string>
#include <iostream>
#include "TextureManager.h"

using namespace std;

class GameObject
{
public:

	GameObject();
	~GameObject();

	virtual void load(int x, int y, int width, int height, string textureID);
	virtual void draw(SDL_Renderer* renderer);
	virtual void update();
	virtual void clean();

protected:
	
	string m_textureID;

	int m_current_frame;
	int m_current_row;

	int m_x;
	int m_y;

	int m_width;
	int m_height;

};