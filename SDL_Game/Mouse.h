#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include <vector>
#include <iostream>

using namespace std;

class Mouse
{

/**
* SDL 2.0 Mouse Buttons identification
*
*	LEFT CLICK          =  0  =  SDL_MOUSE_LEFT
*	SCROLL WHEEL BUTTON =  1  =  SDL_MOUSE_MIDDLE
*	RIGHT CLICK         =  2  =  SDL_MOUSE_RIGHT
*	BOTTOM SIDE BUTTON  =  3  =  SDL_MOUSE_X1
*	UPPER SIDE BUTTON   =  4  =  SDL_MOUSE_X2
*/

public:

	/**
	* \brief: - returns the mouse's singleton -
	*/
	static Mouse* Instance();

	/**
	* \brief - Returns True if the index button is pushed, else False -
	*
	* \parameter button - button's index -
	*
	*/
	bool get_mouse_button_state(int button) { return m_mouse_button_state[button]; };

	/**
	* \brief  -attends the mouse motion-
	*
	* \parameter SDL_Event event : -mouse motion events only-
	*/
	void on_mouse_move(SDL_Event event);

	/**
	* \brief  - attends released buttons -
	*
	* \parameter SDL_Event event : -mouse buttons down events only-
	*/
	void on_button_down(SDL_Event event);

	/**
	* \brief  - attends released buttons -
	*
	* \parameter SDL_Event event : -mouse buttons down events only-
	*/
	void on_button_up(SDL_Event event);

	/**
	* \brief - Returns the mouse's position relative to the SDL window -
	*/
	Vector2D* get_mouse_position() { return m_position; };

	Vector2D* get_relative_position() { return m_rel_position; };

	
private:

	static Mouse* instance;

	Mouse();
	~Mouse() {}

	Vector2D* m_position;
	Vector2D* m_rel_position;

	vector<bool> m_mouse_button_state;

	enum mouse_buttons
	{
		LEFT,	 // click
		MIDDLE,  // scroll wheel button
		RIGHT,	 // click
		BUTTON3, // extra side button
		BUTTON4, // extra side button
		First = LEFT,
		Last = BUTTON4
	};
};

typedef Mouse TheMouse;