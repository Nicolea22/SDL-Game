#ifndef __PLAYER__
#define __PLAYER__
#include "GameObject.h"

class Player : public GameObject
{
public:

	Player();

	void load(int x, int y, int width, int height, string textureID);
	void draw(SDL_Renderer* renderer);
	void update();

protected:
	
	
private:



};
#endif
