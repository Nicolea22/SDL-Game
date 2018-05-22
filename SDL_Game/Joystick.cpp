#include "Joystick.h"

Joystick* Joystick::instance = NULL;

Joystick* Joystick::Instance() 
{
	if (instance == NULL) 
	{
		instance = new Joystick();
		return instance;
	}
	return instance;
}

Joystick::Joystick() 
{
	initialise_joysticks();
}


void Joystick::initialise_joysticks() 
{
	if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if (SDL_NumJoysticks() > 0) 
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++) 
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);

			if (joy) 
			{
				cout << "Joystick " << i << " initialised!" << endl;

				m_joysticks.push_back(joy);
				m_axes_values.push_back(make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));

				vector<bool> temp_buttons;

				for (int j = 0; j < SDL_JoystickNumButtons(joy); j++)
				{
					temp_buttons.push_back(false);
				}
				m_button_states.push_back(temp_buttons);
			}
			else 
			{
				cout << SDL_GetError() << endl;
			}
		}// end for joysticks

		SDL_JoystickEventState(SDL_ENABLE);
		m_joysticks_initialised = true;

		cout << "Initialised " << m_joysticks.size() << " joystick(s)";
	}
	else
		m_joysticks_initialised = false;
}


void Joystick::clean() 
{
	if (m_joysticks_initialised)
	{
		for (unsigned int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}


void Joystick::on_button_down(SDL_Event event)
{
	int which_joy = event.jbutton.which;
	int which_button = event.jbutton.button;

	m_button_states[which_joy][which_button] = true;
}

void Joystick::on_button_up(SDL_Event event)
{
	int which_joy = event.jbutton.which;
	int which_button = event.jbutton.button;

	m_button_states[which_joy][which_button] = false;
}


void Joystick::on_axis_motion(SDL_Event event)
{
	int which_one = event.jaxis.which;

	// left stick move left or right
	if (event.jaxis.axis == 0)
	{
		if (event.jaxis.value > JOYSTICK_RESOLUTION)
		{
			m_axes_values[which_one].first->set_comp_x(1);
		}
		else
			if (event.jaxis.value < -JOYSTICK_RESOLUTION)
			{
				m_axes_values[which_one].first->set_comp_x(-1);
			}
			else {
				m_axes_values[which_one].first->set_comp_x(0);
			}
	}

	// left stick move up or down
	if (event.jaxis.axis == 1)
	{
		if (event.jaxis.value > JOYSTICK_RESOLUTION)
		{
			m_axes_values[which_one].first->set_comp_y(1);
		}
		else
			if (event.jaxis.value < -JOYSTICK_RESOLUTION)
			{
				m_axes_values[which_one].first->set_comp_y(-1);
			}
			else {
				m_axes_values[which_one].first->set_comp_y(0);
			}
	}

	// right stick move left or right
	if (event.jaxis.axis == 3)
	{
		if (event.jaxis.value > JOYSTICK_RESOLUTION)
		{
			m_axes_values[which_one].second->set_comp_x(1);
		}
		else
			if (event.jaxis.value < -JOYSTICK_RESOLUTION)
			{
				m_axes_values[which_one].second->set_comp_x(-1);
			}
			else {
				m_axes_values[which_one].second->set_comp_x(0);
			}
	}

	// right stick move up or down
	if (event.jaxis.axis == 4)
	{
		if (event.jaxis.value > JOYSTICK_RESOLUTION)
		{
			m_axes_values[which_one].second->set_comp_y(1);
		}
		else
			if (event.jaxis.value < -JOYSTICK_RESOLUTION)
			{
				m_axes_values[which_one].second->set_comp_y(-1);
			}
			else {
				m_axes_values[which_one].second->set_comp_x(0);
			}
	}
}

int Joystick::x_value(int joy, int stick)
{
	if (m_axes_values.size() > 0)
	{
		if (stick == 1)
		{
			return m_axes_values[joy].first->get_comp_x();
		}
		if (stick == 2)
		{
			return m_axes_values[joy].second->get_comp_x();
		}
	}
	return 0;
}

int Joystick::y_value(int joy, int stick)
{
	if (m_axes_values.size() > 0)
	{
		if (stick == 1)
		{
			return m_axes_values[joy].first->get_comp_y();
		}
		if (stick == 2)
		{
			return m_axes_values[joy].second->get_comp_y();
		}
	}
	return 0;
}

