#include "GameObject.h"


typedef TextureManager TheTextureManager; // singleton type

GameObject::GameObject() {}


void GameObject::load(int x, int y, int width, int height, string textureID) 
{
	m_x = x;
	m_y = y;

	m_width = width;
	m_height = height;

	m_textureID = textureID;

	m_current_row = 0;
	m_current_frame = 1;
}


void GameObject::draw(SDL_Renderer* renderer) 
{
	TheTextureManager::Instance()->draw_frame(m_textureID, m_x, m_y, m_width, m_height, m_current_row, m_current_frame, 
									 renderer);
}

void GameObject::update() 
{
	m_current_frame = int((SDL_GetTicks()/100) % 6);
	m_x += 1;
}


void GameObject::clean()
{
	cout << "GameObject clean" << endl;
}