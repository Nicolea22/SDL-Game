#ifndef __PLAYER__
#define __PLAYER__
#include "SDLGameObject.h"
#include "Parameters.h"

class Player : public SDLGameObject
{
public:

	Player();

	virtual void draw();
	virtual void update();
	virtual void load(const Parameters* parameters);
	virtual void clean() {};

private:

	void handle_input();
	int life;

	SDLGameObject* go;

	SDL_Rect* green_rect;
	SDL_Rect* red_rect;
};
#endif
