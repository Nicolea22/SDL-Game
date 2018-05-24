#ifndef __GAME__
#define __GAME__
#include "SDLGameObject.h"
#include <vector>
#include "GameStateMachine.h"


class Game
{
public:

	~Game();

	/**
	* \brief init SDL window and renderer objects to show on the screen
	*
	* \param title -window's title-
	* \param x_pos -window's x position on the screen-
	* \param y_pos -window's y position on the screen-
	* \param width -window's width-
	* \param width -window's height-
	* \param window_flag -the window flag, it can be chosen from SDL screen flags-
	* \param init_params -init params to SDL-
	* \param is_running -flag-  default value= true
	*/
	bool init(const char* title, int xpos, int ypos, int width, int height, int window_flag,
		Uint32 init_params, bool is_running = true);

	/**
	* \brief
	*/
	void update();

	/**
	* \brief -Cleans the screen with the setted 'draw color' and draw the new frame-
	*/
	void render();

	/**
	* \brief -Checks every event with polls (keyboard, mouse, etc)-
	*/
	void handleEvents();

	/**
	* \brief -Disallocates from memory SDL windows and renderer obj, and quit SDL-
	*/
	void clean();

	void quit();

	/**
	*	\brief -returns the m_bRunning variable-
	*/
	bool running() { return m_bRunning; };

	SDL_Renderer* get_renderer() const { return m_pRenderer; }

	static Game* Instance();

private:

	Game();

	bool m_bRunning;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	static Game* instance;

	vector<SDLGameObject*> m_gos;

	GameStateMachine* m_pGameMachineState;
};

typedef Game TheGame;

#endif