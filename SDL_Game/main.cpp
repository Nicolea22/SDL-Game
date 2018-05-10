#include "Game.h"


int main(int argc, char* argv[])
{
	Game* game = new Game();
	game->init("SDL tutorial: chapter 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE, 
				SDL_INIT_AUDIO | SDL_INIT_VIDEO);

	while (game->running()) 
	{
		game->handleEvents();
		game->update();
		game->render();
		SDL_Delay(10);
	}

	game->clean();

	return 0;
}



/*
SDL_Window* m_pWindow = 0;
SDL_Renderer* m_pRenderer = 0;


int main(int argc, char* argv[])
{
	// init SDL

	if (SDL_Init(SDL_INIT_EVERYTHING)  >= 0)
	{
		m_pWindow = SDL_CreateWindow("Testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480, SDL_WINDOW_SHOWN);

		// if the window creation succeeded, create our renderer
		if (m_pWindow != NULL)
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	}
	else
		return 1;

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
		
	SDL_Delay(5000);

	SDL_Quit();

	return 0;

}
*/