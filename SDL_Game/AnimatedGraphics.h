#pragma once
#include "SDLGameObject.h"
#include "Parameters.h"

class AnimatedGraphics : public SDLGameObject
{

public:
	AnimatedGraphics(const Parameters* parameters, int anim_speed) :
		SDLGameObject(parameters),
		m_anim_speed(anim_speed)
	{}
	
	virtual void update();


private:

	int m_anim_speed;

};
