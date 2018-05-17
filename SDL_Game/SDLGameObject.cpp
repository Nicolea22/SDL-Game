#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const Parameters* parameters) : GameObject(parameters),
															 m_position(parameters->get_x(), parameters->get_y()),
															 m_velocity(parameters->get_vx(), parameters->get_vy())
{
	m_width = parameters->get_width();
	m_height = parameters->get_height();

	m_textureID = parameters->get_textureID();

	m_current_frame = 1;
	m_current_row = 0;
}

void SDLGameObject::draw(SDL_Renderer* renderer) 
{
	TheTextureManager::Instance()->draw_frame(m_textureID, (int)m_position.get_comp_x(),(int)m_position.get_comp_y(), 
											  m_width, m_height, m_current_row, m_current_frame, renderer);
}


void SDLGameObject::update() 
{
	m_position += m_velocity;
}