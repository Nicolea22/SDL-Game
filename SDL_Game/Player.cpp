#include "Player.h"

Player::Player() {}

void Player::load(int x, int y, int width, int height, string textureID) 
{
	GameObject::load(x, y, width, height, textureID);
}


void Player::draw(SDL_Renderer* renderer) 
{
	GameObject::draw(renderer);
}

void Player::update()
{
	m_current_frame = int((SDL_GetTicks() / 100) % 6);
	m_x -= 1;
}