#pragma once
#include "GameObject.h"
#include "Vector2D.h"

// singleton calling class
typedef TextureManager TheTextureManager;

class SDLGameObject : public GameObject
{
public:
	
	SDLGameObject(const Parameters* parameters);
	
	virtual void draw();
	virtual void update();
	virtual void clean() {};
	
	virtual bool in(Vector2D* pos);

protected:

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	
	int m_width;
	int m_height;

	int m_current_frame;
	int m_current_row;

	string m_textureID;
};