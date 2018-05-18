#include "Enemy.h"

Enemy::Enemy(const Parameters* parameters): SDLGameObject(parameters)
{}

void Enemy::update() 
{
	m_current_frame = (int)SDL_GetTicks() / 60 % 6;
	SDLGameObject::update();
}