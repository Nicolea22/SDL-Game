#include "MenuButton.h"
#include "Vector2D.h"
#include "InputHandler.h"

MenuButton::MenuButton(Parameters* parameters) : SDLGameObject(parameters)
{
	m_current_frame = MOUSE_OUT;
}

void MenuButton::render() 
{
	SDLGameObject::draw();
}

void MenuButton::update()
{
	Vector2D* p_mouse_pos = TheInputHandler::Instance()->get_mouse_position();
	
	if (in(*p_mouse_pos)) 
	{
		m_current_frame = MOUSE_OVER;
		
		// 1 = left click
		if (TheInputHandler::Instance()->get_mouse_button_state(0)) 
		{
			m_current_frame = CLICKED;
		}
		else 
		{
			m_current_frame = MOUSE_OUT;
		}
	}
}


void MenuButton::clean() 
{
	SDLGameObject::clean();
}