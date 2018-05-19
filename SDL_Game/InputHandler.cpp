#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::instance = NULL;

InputHandler* InputHandler::Instance()
{
	if (instance == NULL)
	{
		instance = new InputHandler();
		return instance;
	}
	return instance;
}


void InputHandler::initialise_joysticks() 
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
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
				cout << "joystick " << i << " initialiased!" << endl;
				m_joysticks.push_back(joy);
				m_joystick_values.push_back(make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));
			}
			else
			{
				cout << SDL_GetError() << endl;
			}
		}
		 
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialised = true;

		std::cout << "Initialised " << m_joysticks.size() << " joystick(s)";
	}
	else
		m_bJoysticksInitialised = false;
}


void InputHandler::update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) 
	{
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
					}else 
						{			
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
					}else
						{
							m_joystick_values[which_one].first->set_comp_y(0);
						}
			}

			// right stick move left or right
			if (event.jaxis.axis == 3) 
			{
				if (event.jaxis.value > JOYSTICK_RESOLUTION)
				{
					m_joystick_values[which_one].second->set_comp_x(1);
				}
				else
					if (event.jaxis.value < -JOYSTICK_RESOLUTION)
					{
						m_joystick_values[which_one].second->set_comp_x(-1);
					}
					else
					{
						m_joystick_values[which_one].second->set_comp_x(0);
					}
			}

			// right stick move up or down
			if (event.jaxis.axis == 4) 
			{
				if (event.jaxis.value > JOYSTICK_RESOLUTION)
				{
					m_joystick_values[which_one].second->set_comp_y(1);
				}
				else
					if (event.jaxis.value < -JOYSTICK_RESOLUTION)
					{
						m_joystick_values[which_one].second->set_comp_y(-1);
					}
					else
					{
						m_joystick_values[which_one].second->set_comp_x(0);
					}
			}

		}// if joystick event
	}// while poll event
}


void InputHandler::clean() 
{
	if (m_bJoysticksInitialised) 
	{
		for(unsigned int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}

int InputHandler::x_value(int joy, int stick)
{
	if (m_joystick_values.size() > 0) 
	{
		if (stick == 1) 
		{
			return m_joystick_values[joy].first->get_comp_x();
		}
		if (stick == 2) 
		{
			return m_joystick_values[joy].second->get_comp_x();
		}
	}
	return 0;
}

int InputHandler::y_value(int joy, int stick)
{
	if (m_joystick_values.size() > 0)
	{
		if (stick == 1)
		{
			return m_joystick_values[joy].first->get_comp_y();
		}
		if (stick == 2)
		{
			return m_joystick_values[joy].second->get_comp_y();
		}
	}
	return 0;
}