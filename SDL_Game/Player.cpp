#include "Player.h"
#include "InputHandler.h"
#include "Game.h"

Player::Player() : SDLGameObject()
{
	flip = SDL_FLIP_HORIZONTAL;

	m_velocity = 0;
	life = 900;

	go = new SDLGameObject();
	go->load(new Parameters(m_position.get_comp_x() + 40, m_position.get_comp_y() + 30, 168, 48, "gatling", 5));
	go->set_scale(Vector2D(0.5f, 0.5f));
	go->set_flip(SDL_FLIP_HORIZONTAL);

	set_scale(Vector2D(1.0f, 1.0f));

	green_rect = new SDL_Rect();
	red_rect = new SDL_Rect();

	green_rect->h = 2;
	green_rect->w = 60;

	red_rect->h = 2;
	red_rect->w = 60;

	green_rect->x = m_position.get_comp_x() + 40;
	green_rect->y = m_position.get_comp_y() - 40;

	red_rect->x = m_position.get_comp_x() + 40;
	red_rect->y = m_position.get_comp_y() - 40;
}

void Player::load(const Parameters* parameters) 
{
	SDLGameObject::load(parameters);
}

void Player::draw()
{
	SDLGameObject::draw();

	SDL_SetRenderDrawColor(TheGame::Instance()->get_renderer(), 255, 0, 0, 0);
	SDL_RenderFillRect(TheGame::Instance()->get_renderer(), red_rect);

	SDL_SetRenderDrawColor(TheGame::Instance()->get_renderer(), 0, 255, 0, 0);
	SDL_RenderFillRect(TheGame::Instance()->get_renderer(), red_rect);
	
	go->draw();

}

void Player::update()
{
	InputHandler* handler = TheInputHandler::Instance();

	SDLGameObject::update();
	go->set_pos(Vector2D(m_position.get_comp_x() + 40, m_position.get_comp_y() + 25));

	m_acceleration = 0;

	handle_input();

	if (m_velocity.get_comp_x() > 0)
	{
		flip = SDL_FLIP_HORIZONTAL;
		angle = m_velocity.get_angle_arcsen();
	}
	else
	{
		if (m_velocity.get_comp_x() < 0)
		{
			flip = SDL_FLIP_NONE;
			angle = -m_velocity.get_angle_arcsen();
		}
	}

	green_rect->x = m_position.get_comp_x() + 40;
	green_rect->y = m_position.get_comp_y() - 20;

	red_rect->x = m_position.get_comp_x() + 40;
	red_rect->y = m_position.get_comp_y() - 20;

	m_current_frame = (int)SDL_GetTicks() / 100 % m_num_frames;
}


void Player::handle_input()
{
	InputHandler* handler = TheInputHandler::Instance();

	// joystick actions
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

	// mouse actions
	Vector2D mouse_position = *handler->get_mouse_position() + Vector2D(-64, -41);

	Vector2D aux = mouse_position - m_position;

	go->set_angle(aux.get_angle_arctg());

	if (handler->get_mouse_button_state(0))
	{
		m_velocity = aux;

		m_velocity.normalize();
	}
	else 
	{
		m_velocity = 0;
	}

	// keyboard actions
	if (TheInputHandler::Instance()->is_key_down(SDL_SCANCODE_W))
	{
		m_velocity.set_comp_y(-.9f);
		m_velocity.set_comp_x(0);
	}

	if (TheInputHandler::Instance()->is_key_down(SDL_SCANCODE_S))
	{
		m_velocity.set_comp_y(.9f);
		m_velocity.set_comp_x(0);
	}
}