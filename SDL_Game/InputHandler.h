#pragma once
#include "Vector2D.h"
#include "Joystick.h"
#include "Mouse.h"
#include "Keyboard.h"


using namespace std;


class InputHandler
{
public:

	const int JOYSTICK_RESOLUTION = 10000;

	void update();

	/**
	* \brief: - clean the memory calling all the clean functions -
	*/
	void clean() 
	{
		TheJoystick::Instance()->clean(); 
	};

	/**
	* \brief - initialise all the joysticks -
	*/
	void initialise_joysticks() { TheJoystick::Instance()->initialise_joysticks(); };

	/**
	* \brief - -
	*/
	bool joystick_initialised() { return TheJoystick::Instance()->joystick_initialised(); };

	/**
	* \brief - Returns the mouse's position relative to the SDL window -
	*/
	Vector2D* get_mouse_position() { return TheMouse::Instance()->get_mouse_position(); };

	/**
	* \brief - Return True if button is being pressed, else False -
	*
	* \parameter joy    - Joystick ID -
	* \parameter button - Button ID -
	*/
	bool get_joystick_button_state(int joy, int button) { return TheJoystick::Instance()->get_button_state(joy, button); };

	/**
	* \brief            --
	*
	* \parameter button --
	*
	*/
	bool get_mouse_button_state(int button) { return TheMouse::Instance()->get_mouse_button_state(button); };

	/**
	* \brief         - if (any key with key_code pressed from keyboard) return true; else return false -
	*
	* \parameter key - key code pressed -
	*
	* ..This function is working with Keyboard events..
	*/
	bool is_key_down(SDL_Scancode key_code) { return TheKeyboard::Instance()->is_key_down(key_code); };

	/**
	* \brief		   - Returns the joystick of the id given by parameter -
	*
	* \parameter index - Joystick identification -
	*
	*/
	SDL_Joystick* get_joystick(int index) { return TheJoystick::Instance()->get_joystick(index); };

	/**
	* \brief           - Returns the x comp if the stick was moved -
	*
	* \parameter joy   - Joystick ID -
	* \parameter stick - Stick number -
	*
	*/
	int x_value(int joy, int stick) { return TheJoystick::Instance()->x_value(joy, stick); };

	/**
	* \brief           - Returns the y comp if the stick was moved -
	*
	* \parameter joy   - Joystick ID -
	* \parameter stick - Stick number -
	*
	*/
	int y_value(int joy, int stick) { return TheJoystick::Instance()->y_value(joy, stick); };

	static InputHandler* Instance();

private:

	InputHandler();
	~InputHandler() {};

	static InputHandler* instance;



};

typedef InputHandler TheInputHandler;
