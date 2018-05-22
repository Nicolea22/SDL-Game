#include "Mouse.h"

Mouse* Mouse::instance = NULL;

Mouse* Mouse::Instance() 
{
	if (instance == NULL)
	{
		instance = new Mouse();
		return instance;
	}
	return instance;
}


Mouse::Mouse()
{
	// set mouse buttons to false
	for (int i = First; i <= Last; i++)
	{
		m_mouse_button_state.push_back(false);
	}

	// set to 0 to avoid ´non initialised object´ errors
	m_position = new Vector2D(0, 0);
	m_rel_position = new Vector2D(0, 0);
}

void Mouse::on_mouse_move(SDL_Event event) 
{
	m_position->set_comp_x(event.motion.x);
	m_position->set_comp_y(event.motion.y);
}

void Mouse::on_button_down(SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouse_button_state[LEFT] = true;
	}

	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouse_button_state[RIGHT] = true;
	}

	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouse_button_state[MIDDLE] = true;
	}

	if (event.button.button == SDL_BUTTON_X1)
	{
		m_mouse_button_state[BUTTON3] = true;
	}

	if (event.button.button == SDL_BUTTON_X2)
	{
		m_mouse_button_state[BUTTON4] = true;
	}
}

void Mouse::on_button_up(SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouse_button_state[LEFT] = false;
	}

	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouse_button_state[RIGHT] = false;
	}

	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouse_button_state[MIDDLE] = false;
	}

	if (event.button.button == SDL_BUTTON_X1)
	{
		m_mouse_button_state[BUTTON3] = false;
	}

	if (event.button.button == SDL_BUTTON_X2)
	{
		m_mouse_button_state[BUTTON4] = false;
	}
}
