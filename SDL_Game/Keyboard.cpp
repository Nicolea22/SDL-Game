#include "Keyboard.h"

Keyboard* Keyboard::instance = NULL;

Keyboard* Keyboard::Instance()
{
	if (instance == NULL)
	{
		instance = new Keyboard();
		return instance;
	}
	return instance;
}

bool Keyboard::is_key_down(SDL_Scancode key)
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

void Keyboard::set_keys_to_false() 
{
	m_keyboard_state = SDL_GetKeyboardState(0);
}
