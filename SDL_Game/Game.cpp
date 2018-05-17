#include <iostream>
#include "Game.h"
#include "Enemy.h"
#include "Player.h"

using namespace std;

typedef TextureManager TheTextureManager;

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
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
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

	TheTextureManager::Instance()->load("assets/animatealpha.png", "animate", m_pRenderer);
	TheTextureManager::Instance()->load("assets/background.jpg", "background", m_pRenderer);

	//m_gos.push_back(new Player(new Parameters(500, 100, 128, 82, "animate")));
	m_gos.push_back(new Enemy(new Parameters(-100, 350, 1, 0, 128, 82, "animate")));

	cout << "Init success!" << endl; // everything succededs
	return true;
}

void Game::update() 
{
	for (int i = 0; i < m_gos.size(); i++)
	{
		m_gos[i]->update();
	}
}

void Game::render() 
{
	SDL_RenderClear(m_pRenderer); // clear the screen with the draw color to draw a new updated frame
	
	TheTextureManager::Instance()->draw("background", 0, 0, 640, 480, get_renderer());

	for (int i = 0; i < m_gos.size(); i++) 
	{
		m_gos[i]->draw(get_renderer());
	}

	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	cout << "Cleaning game!" << endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
	IMG_Quit();
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

