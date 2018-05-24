#include "Parameters.h"
#include "SDLGameObject.h"

class MenuButton : public SDLGameObject
{

public:
	
	MenuButton(Parameters* parameters);

	virtual void render();
	virtual void update();
	virtual void clean();

private:

	enum button_state 
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED  = 2
	};

};