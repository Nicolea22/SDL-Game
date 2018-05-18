#include "SDL.h"
#include <iostream>
#include <vector>
#include "Vector2D.h"

using namespace std;

class InputHandler
{
public:
	
	const int m_joystick_deadzone = 10000;

	void update();
	void clean();

	void initialise_joysticks();

	bool joystick_initialised() { return m_bJoysticksInitialised; };

	int x_value(int joy, int stick);
	int y_value(int joy, int stick);

	static InputHandler* Instance();

private:

	InputHandler() {};
	~InputHandler() {};

	static InputHandler* instance;
	
	vector < SDL_Joystick* > m_joysticks;
	vector < pair< Vector2D* , Vector2D* >> m_joystick_values;
	bool m_bJoysticksInitialised;
};

typedef InputHandler TheInputHandler;
