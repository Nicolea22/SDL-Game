#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() 
{
}

Game::~Game()
{}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int window_flag, Uint32 init_param, bool is_running) 
{
	m_bRunning = is_running;
	
	// attempts to initialize SDL
	if (SDL_Init(init_param) == 0)
	{
		cout << "SDL Init success" << endl;
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, window_flag);

		if (m_pWindow != NULL)
		{
			// init renderer
			cout << "Window creation success" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

			if (m_pRenderer != NULL) 
			{
				// set the renderer obj
				cout << "Renderer creation succes" << endl;
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255 , 255, 255);
			}
		}
		else 
		{
			cout << "Renderer creation fail!" << endl;
			m_bRunning = false;
			return false;
		}
	}
	else 
	{
		cout << "Window creation fail!" << endl;
		m_bRunning = false;
		return false;
	}

	cout << "Init success" << endl; // everything succededs
	return true;
}

void Game::update() 
{
	
}

void Game::render() 
{
	SDL_RenderClear(m_pRenderer); // clear the screen with the draw color to draw a new updated frame
	SDL_RenderPresent(m_pRenderer); // draw the new frame
}

void Game::clean()
{
	cout << "Cleaning game!" << endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}


void Game::handleEvents() 
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}

	}
}

