#pragma once
#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class TextureManager 
{
public:

	TextureManager();
	~TextureManager();

	/**
	*\brief -Load an image-
	*
	*\parameter fileName - image's path -
	*\parameter id - texture identification -
	*\parameter renderer - obj to draw -
	*/
	bool load(string file_name, string id, SDL_Renderer* renderer);

	/**
	*\brief draw -draw a entire sprite sheet on the screen-
	*/
	void draw(string id, int x, int y, int width, int height, SDL_Renderer* renderer, 
			  SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	/**
	*\brief draw_frame -only draw the sprite sheet's tiles (frames) animated-	
	*
	*\parameter id - texture identification -
	*\parameter x  - x position on the screen -
	*\parameter y  - y position on the screen -
	*\parameter width - texture width - 
	*\parameter height - texture height -
	*\parameter current_row - row value in the sprite sheet -
	*\parameter current_frame - current frame to draw -
	*\parameter renderer - obj to draw -
	*\parameter flip - flip the texture - default value= 'SDL_FLIP_NONE'
	*/
	void draw_frame(string id, int x, int y, int width, int height, int current_row, int current_frame
				   ,SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:

	std::map<std::string, SDL_Texture*> m_textureMap;

};