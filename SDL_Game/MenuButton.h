#pragma once
#include "Parameters.h"
#include "SDLGameObject.h"

class MenuButton : public SDLGameObject
{

public:

	MenuButton(void(*callback)());

	virtual void load(const Parameters* parameters);
	virtual void draw();
	virtual void update();
	virtual void clean();

private:

	void(*m_callback)();

	bool m_bReleased;



	enum button_state 
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED  = 2
	};

};