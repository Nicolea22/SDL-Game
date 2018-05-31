#pragma once
#include "GameObject.h"
#include "Vector2D.h"
#include "Parameters.h"

// singleton calling class
typedef TextureManager TheTextureManager;

class SDLGameObject : public GameObject
{
public:

	SDLGameObject();

	virtual void draw();
	virtual void update();
	virtual void load(const Parameters* parameters);
	virtual void clean() {}

	virtual void set_flip(SDL_RendererFlip flip) { this->flip = flip; }
	virtual void set_angle(float angle) { this->angle = angle; }

	int get_width() { return m_width; }
	int get_height() { return m_height; }

	Vector2D& get_pos() { return m_position; }
	Vector2D& get_vel() { return m_velocity; }

	void set_pos(Vector2D v) {
							   m_position.set_comp_x(v.get_comp_x());
							   m_position.set_comp_y(v.get_comp_y()); 
							 }

	void set_scale(Vector2D v) {
								m_scale.set_comp_x(v.get_comp_x());
								m_scale.set_comp_y(v.get_comp_y());
							   }

	virtual bool in(Vector2D* pos);

protected:

	Vector2D m_position;
	Vector2D m_velocity ;
	Vector2D m_acceleration;

	Vector2D m_scale;
	
	int m_width;
	int m_height;

	float angle;

	int m_num_frames;

	int m_current_frame;
	int m_current_row;

	SDL_RendererFlip flip;

	string m_textureID;

};