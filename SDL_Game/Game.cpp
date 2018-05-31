#include <iostream>
#include "Game.h"
#include "InputHandler.h"
#include "Enemy.h"
#include "Menustate.h"
#include "Playstate.h"
#include "Global.h"

using namespace std;

Game* Game::instance = NULL;

Game* Game::Instance() 
{
	if (instance == NULL) 
	{
		instance = new Game();
		return instance;
	}
	return instance;
}

Game::Game()
{}

Game::~Game()
{}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int window_flag, Uint32 init_param, bool is_running)
{
	m_bRunning = is_running;

	// attempts to initialize SDL
	if (SDL_Init(init_param) == 0)
	{
		cout << "SDL Init success!" << endl;

		SDL_ShowCursor(SDL_ENABLE);

		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, window_flag);

		if (m_pWindow != NULL)
		{
			// init renderer
			cout << "Window creation success!" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

			if (m_pRenderer != NULL)
			{
				// set the renderer obj
				cout << "Renderer creation succes!" << endl;
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
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

	m_pGameMachineState = new GameStateMachine();

	m_pGameMachineState->change_state(new MenuState());

	cout << "Init success!" << endl; // everything succededs

	return true;
}

void Game::update() 
{
	m_pGameMachineState->update();
}

void Game::render() 
{
	SDL_RenderClear(m_pRenderer); // clear the screen with the draw color to draw a new updated frame
	
	m_pGameMachineState->render();

	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	cout << "Cleaning game!" << endl;
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
	IMG_Quit();
}

void Game::quit()
{
	cout << "SDL Window closed!!!" << endl;
	m_bRunning = false;
}

void Game::handleEvents() 
{
	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->is_key_down(SDL_SCANCODE_RETURN)) 
	{
		m_pGameMachineState->change_state(new PlayState());
	}
}

