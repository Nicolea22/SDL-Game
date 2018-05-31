#include "SDLGameObject.h"
#include "Game.h"


SDLGameObject::SDLGameObject() : GameObject()
{
}


void SDLGameObject::load(const Parameters* parameters)
{
	m_position = parameters->get_pos();
	m_velocity = Vector2D(0, 0);
	m_acceleration = Vector2D(0, 0);

	m_width = parameters->get_width();
	m_height = parameters->get_height();

	m_textureID = parameters->get_textureID();

	m_num_frames = parameters->get_num_frames();
	
	angle = 0;

	m_current_frame = 0;
	m_current_row = 0;
}


void SDLGameObject::draw()
{
	TheTextureManager::Instance()->draw_frame(m_textureID, (int)m_position.get_comp_x(), (int)m_position.get_comp_y(),
											  m_width, m_height, m_current_row, m_current_frame, angle, m_scale,
											  TheGame::Instance()->get_renderer(), flip);
}


void SDLGameObject::update() 
{
	m_position += m_velocity;
	m_velocity += m_acceleration;
}


bool SDLGameObject::in(Vector2D* pos) 
{
	// if position is inside, return true else return false
	if (pos->get_comp_x() > m_position.get_comp_x()             &&

		pos->get_comp_x() < (m_position.get_comp_x() + m_width) &&

		pos->get_comp_y() > m_position.get_comp_y()             &&

		pos->get_comp_y() < (m_position.get_comp_y() + m_height))
	{
		return true;
	}
	return false;
}


