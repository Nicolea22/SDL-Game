#ifndef __PLAYER__
#define __PLAYER__
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:

	Player(const Parameters* parameters);

	virtual void update();
	virtual void clean() {};

};
#endif
