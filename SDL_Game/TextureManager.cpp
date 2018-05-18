#include "TextureManager.h"
#include <iostream>

TextureManager* TextureManager::instance = 0;

TextureManager* TextureManager::Instance()
{
	if (instance == NULL)
	{
		instance = new TextureManager();
		return instance;
	}
	return instance;
}

bool TextureManager::load(string file_name, string id, SDL_Renderer* renderer) 
{
	SDL_Surface* temp_surface = IMG_Load(file_name.c_str());

	if (temp_surface == 0) 
	{
		// if texture didnt load
		cout << "Image loading fail!" << endl;
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);

	SDL_FreeSurface(temp_surface);

	//if everything is ok, add the texture to our map
	if (texture != 0) 
	{
		m_textureMap[id] = texture;
		cout << "Texture " <<"'"<< id <<"'"<<" creation success!" << endl;
		return true;
	}

	// if something went wrong
	cout << "Texture creation fail!" << endl;
	return false;
}

void TextureManager::draw(string id, int x, int y, int width, int height, SDL_Renderer* renderer,
						  SDL_RendererFlip flip)
{
	SDL_Rect src_rect;
	SDL_Rect dest_rect;

	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.w = dest_rect.w = width;
	src_rect.h = dest_rect.h = height;

	dest_rect.x = x;
	dest_rect.y = y;

	SDL_RenderCopyEx(renderer, m_textureMap[id], &src_rect, &dest_rect, 0, 0, flip);
}


void TextureManager::draw_frame(string id, int x, int y, int width, int height, int current_row, int current_frame,
	SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_Rect src_rect;
	SDL_Rect dest_rect;

	src_rect.x = width * current_frame;
	src_rect.y = height * current_row;

	src_rect.w = dest_rect.w = width;
	src_rect.h = dest_rect.h = height;

	dest_rect.x = x;
	dest_rect.y = y;

	SDL_RenderCopyEx(renderer, m_textureMap[id], &src_rect, &dest_rect, 0, 0, flip);
}


