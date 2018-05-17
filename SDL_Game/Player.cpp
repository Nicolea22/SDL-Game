#include "Player.h"

Player::Player(const Parameters* parameters) : SDLGameObject(parameters)
{}

void Player::update()
{
	SDLGameObject::update();
	m_current_frame = (int)SDL_GetTicks() / 100 % 6;
}