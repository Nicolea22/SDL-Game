#include "Player.h"
#include "InputHandler.h"


Player::Player(const Parameters* parameters) : SDLGameObject(parameters)
{}

void Player::update()
{
	InputHandler* handler = TheInputHandler::Instance();

	SDLGameObject::update();
	
	Vector2D mouse_position = *TheInputHandler::Instance()->get_mouse_position() + Vector2D(-64, -41);

	if (handler->get_mouse_button_state(0))
	{
		m_velocity = (mouse_position - m_position);

		m_velocity.normalize();
	}
	else
		m_velocity = 0;

	if (m_velocity.get_comp_x() < 0) 
	{
		TheTextureManager::Instance()->flip_image(SDL_FLIP_HORIZONTAL);
	}else
		if(m_velocity.get_comp_x() > 0)
			TheTextureManager::Instance()->flip_image(SDL_FLIP_NONE);
	/*
	cout << "velocidad en x: " << m_velocity.get_comp_x() << endl;
	cout << "velocidad en y: " << m_velocity.get_comp_y() << endl;

	cout << endl;
	cout << endl;
	*/
	m_acceleration = 0;

	handle_input();

	m_current_frame = (int)SDL_GetTicks() / 100 % 6;
}


void Player::handle_input()
{
	InputHandler* handler = TheInputHandler::Instance();

	if (TheInputHandler::Instance()->joystick_initialised())
	{
		if (handler->x_value(0, 1) > 0 || handler->x_value(0, 1) < 0)
			m_velocity.set_comp_x(1 * handler->x_value(0, 1));

		if (handler->y_value(0, 1) > 0 || handler->y_value(0, 1) < 0)
			m_velocity.set_comp_y(1 * handler->y_value(0, 1));

		if (handler->get_joystick_button_state(0, 3))
		{
			m_velocity.set_comp_x(5);
		}
	}// if joystick initialiased

}