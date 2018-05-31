#include "MenuButton.h"
#include "Vector2D.h"
#include "InputHandler.h"
#include "Global.h"

MenuButton::MenuButton(void (*callback)()) : SDLGameObject(), m_callback(callback)
{
	m_current_frame = MOUSE_OUT;
}

void MenuButton::load(const Parameters* parameters) 
{
	SDLGameObject::load(parameters);
}

void MenuButton::draw() 
{
	SDLGameObject::draw();
}

void MenuButton::update()
{
	Vector2D* mouse_pos = TheInputHandler::Instance()->get_mouse_position();

	if (in(mouse_pos))
	{
		// 1 = left click
		if (TheInputHandler::Instance()->get_mouse_button_state(0))
		{
			m_current_frame = CLICKED;

			m_callback();

			m_bReleased = false;
		}
		else
		{
			m_bReleased = true;
			m_current_frame = MOUSE_OUT;
		}
	}
	else 
	{
		m_current_frame = MOUSE_OUT;
	}
}

void MenuButton::clean() 
{
	SDLGameObject::clean();
}