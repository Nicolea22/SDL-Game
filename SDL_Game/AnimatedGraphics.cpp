#include "AnimatedGraphics.h"

void AnimatedGraphics::update() 
{
	m_current_frame = SDL_GetTicks() / (m_anim_speed)  % m_num_frames;
}