#include "Player.h"
#include "InputHandler.h"

Player::Player(const Parameters* parameters) : SDLGameObject(parameters)
{}

void Player::update()
{
	SDLGameObject::update();

	m_velocity.set_comp_x(0);
	m_acceleration.set_comp_x(0);

	handle_input();

	m_current_frame = (int)SDL_GetTicks() / 100 % 6;
}


void Player::handle_input() 
{
	InputHandler* joystick = TheInputHandler::Instance();

	if (TheInputHandler::Instance()->joystick_initialised())
	{
		if (joystick->x_value(0, 1) > 0 || joystick->x_value(0, 1) < 0)
			m_velocity.set_comp_x(1 * joystick->x_value(0, 1));

		if (joystick->y_value(0, 1) > 0 || joystick->y_value(0, 1) < 0)
			m_velocity.set_comp_x(1 * joystick->y_value(0, 1));

	}
}