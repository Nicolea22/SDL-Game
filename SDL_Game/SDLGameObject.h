#pragma once
#include "GameObject.h"
#include "Vector2D.h"

// singleton calling class
typedef TextureManager TheTextureManager;

class SDLGameObject : public GameObject
{
public:
	
	SDLGameObject(const Parameters* parameters);
	
	virtual void draw(SDL_Renderer* renderer);
	virtual void update();
	virtual void clean() {};

protected:

	Vector2D m_position;
	Vector2D m_velocity;
	
	int m_width;
	int m_height;

	int m_current_frame;
	int m_current_row;

	string m_textureID;
};