#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::instance = NULL;

InputHandler::InputHandler()
{}

InputHandler* InputHandler::Instance()
{
	if (instance == NULL)
	{
		instance = new InputHandler();
		return instance;
	}
	return instance;
}


void InputHandler::update()
{
	m_keyboard_state = SDL_GetKeyboardState(0);

	SDL_Event event;

	while (SDL_PollEvent(&event))
	{

		switch (event.type)
		{

		case SDL_QUIT:
			TheGame::Instance()->quit();
		break;

		case SDL_JOYAXISMOTION:
			TheJoystick::Instance()->on_axis_motion(event);
		break;

		case SDL_JOYBUTTONDOWN:
			TheJoystick::Instance()->on_button_down(event);
		break;

		case SDL_JOYBUTTONUP:
			TheJoystick::Instance()->on_button_up(event);
		break;

		case SDL_MOUSEBUTTONDOWN:
			TheMouse::Instance()->on_button_down(event);
		break;

		case SDL_MOUSEBUTTONUP:
			TheMouse::Instance()->on_button_up(event);
		break;

		case SDL_MOUSEMOTION:
			TheMouse::Instance()->on_mouse_move(event);
		break;

		case SDL_KEYDOWN:
			// TODO: add keyboard buttons event
		break;


		case SDL_KEYUP:
			// TODO: add keyboard buttons event
		break;

		default:
			break;
		}

		
	}// while poll event
}

bool InputHandler::is_key_down(SDL_Scancode key)
{
	if (m_keyboard_state != 0) 
	{
		if (m_keyboard_state[key] == 1) 
		{
			return true;
		}
		else
			return false;
	}

	return false;
}





/*
********** THIS IS AN EX UPDATE HARDCODED FUNCTION ************


	if (event.type == SDL_QUIT)
	{
		TheGame::Instance()->clean();
	}


	if (event.type == SDL_JOYAXISMOTION)
	{
		int which_one = event.jaxis.which;

		// left stick move left or right
		if (event.jaxis.axis == 0)
		{
			if (event.jaxis.value > JOYSTICK_RESOLUTION)
			{
				m_joystick_values[which_one].first->set_comp_x(1);
			}else
				if (event.jaxis.value < -JOYSTICK_RESOLUTION)
				{
					m_joystick_values[which_one].first->set_comp_x(-1);
				}else{
					m_joystick_values[which_one].first->set_comp_x(0);
				}
		}

		// left stick move up or down
		if (event.jaxis.axis == 1)
		{
			if (event.jaxis.value > JOYSTICK_RESOLUTION)
			{
				m_joystick_values[which_one].first->set_comp_y(1);
			}else
				if (event.jaxis.value < -JOYSTICK_RESOLUTION)
				{
					m_joystick_values[which_one].first->set_comp_y(-1);
				}else{
					m_joystick_values[which_one].first->set_comp_y(0);
				}
		}

		// right stick move left or right
		if (event.jaxis.axis == 3)
		{
			if (event.jaxis.value > JOYSTICK_RESOLUTION)
			{
				m_joystick_values[which_one].second->set_comp_x(1);
			}else
				if (event.jaxis.value < -JOYSTICK_RESOLUTION)
				{
					m_joystick_values[which_one].second->set_comp_x(-1);
				}else{
					m_joystick_values[which_one].second->set_comp_x(0);
				}
		}

		// right stick move up or down
		if (event.jaxis.axis == 4)
		{
			if (event.jaxis.value > JOYSTICK_RESOLUTION)
			{
				m_joystick_values[which_one].second->set_comp_y(1);
			}else
				if (event.jaxis.value < -JOYSTICK_RESOLUTION)
				{
					m_joystick_values[which_one].second->set_comp_y(-1);
				}else{
					m_joystick_values[which_one].second->set_comp_x(0);
				}
		}
	}// if joystick event


	// joystick buttons event
	if (event.type == SDL_JOYBUTTONDOWN)
	{
		int which_one = event.jaxis.which;

		m_button_states[which_one][event.jbutton.button] = true;
	}

	if (event.type == SDL_JOYBUTTONUP)
	{
		int which_one = event.jaxis.which;

		m_button_states[which_one][event.jbutton.button] = false;
	}


	// mouse buttons event
	if (event.type == SDL_MOUSEBUTTONUP)
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

	if (event.type == SDL_MOUSEBUTTONDOWN)
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
	} // if mouse buttons event


	// mouse motion
	if (event.type == SDL_MOUSEMOTION)
	{
		m_mouse_position->set_comp_x(event.motion.x);
		m_mouse_position->set_comp_y(event.motion.y);
	}
*/


