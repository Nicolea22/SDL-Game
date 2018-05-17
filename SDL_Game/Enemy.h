#pragma once
#include "SDLGameObject.h"


class Enemy : public SDLGameObject
{
public:

	Enemy(const Parameters* parameters);

	virtual void update();
	virtual void clean() {};
};