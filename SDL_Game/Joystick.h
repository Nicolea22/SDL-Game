#pragma once
#include "Vector2D.h"
#include "SDL.h"
#include <vector>
#include <iostream>

using namespace std;

class Joystick
{
	/** SDL 2.0 XBOX joystick Buttons identification
	*  <SDL_Joystick.h>
	*
	*	A          = 0
	*	B		   = 1
	*	X          = 2
	*	Y          = 3
	*	LB         = 4
	*	RB         = 5
	*	LT         = ?
	*	RT         = ?
	*	Select     = 6
	*	Start      = 7
	*	L3         = 8
	*	R3         = 9
	*	DPad Up    = ?
	*	DPad Down  = ?
	*	DPad Left  = ?
	*	DPad Right = ?
	*
	*/

public:

	const int JOYSTICK_RESOLUTION = 10000;

	/**
	* \brief: -returns the joystick's singleton-
	*/
	static Joystick* Instance();

	/**
	* \brief: - delete the joystick instance from memory -
	*/
	void clean();

	/**
	* \brief - initialise all the joysticks -
	*/
	void initialise_joysticks();

	/**
	* \brief - returns True if joystick is initialised, else returns False-
	*/
	bool joystick_initialised() { return m_joysticks_initialised; };

	/**
	* \brief - Return True if button number is being pressed, else False -
	*
	* \parameter joy           -Joystick ID-
	* \parameter button_number - Button ID -
	*/
	bool get_button_state(int joy, int button_number) { return m_button_states[joy][button_number]; };

	/**
	* \brief  -attends released buttons -
	* 
	* \parameter SDL_Event event : -joystick buttons down events only-
	*/
	void on_button_down(SDL_Event event);

	/**
	* \brief  -attends pushed buttons-
	*
	* \parameter SDL_Event event : -joystick buttons up events only-
	*/
	void on_button_up(SDL_Event event);

	/**
	* \brief  -attends the axes motion-
	*
	* \parameter SDL_Event event : -joystick axes motion events only-
	*/
	void on_axis_motion(SDL_Event event);

	/**
	* \brief - Returns the x comp if the stick was moved -
	*
	* \parameter joy   - Joystick ID -
	* \parameter stick - Stick number -
	*
	*/
	int x_value(int joy, int stick);

	/**
	* \brief Returns the y comp if the stick was moved           --
	*
	* \parameter joy   - Joystick ID -
	* \parameter stick - Stick number -
	*
	*/
	int y_value(int joy, int stick);

	SDL_Joystick* get_joystick(int index) { return m_joysticks[index]; };

private:

	Joystick();
	~Joystick() {}
	
	static Joystick* instance;

	vector < SDL_Joystick* > m_joysticks;
	vector < pair< Vector2D*, Vector2D* >> m_axes_values;

	vector<vector<bool>> m_button_states;
	
	bool m_joysticks_initialised;
};

typedef  Joystick TheJoystick;

