#pragma once
#include "SDL.h"

class Keyboard
{

public:


	static Keyboard* Instance();

	/**
	* \brief         - if (any key with key_code pressed from keyboard) return true; else return false -
	*
	* \parameter key - key code pressed -
	*
	* ..This function is working with Keyboard events..
	*/
	bool is_key_down(SDL_Scancode key_code);

	/**
	* \brief - set all the keys to false -
	*
	*/
	void set_keys_to_false();

private:

	static Keyboard* instance;

	const Uint8* m_keyboard_state;

};

typedef Keyboard TheKeyboard;