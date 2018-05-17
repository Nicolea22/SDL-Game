#pragma once
#include <string>
#include <iostream>
#include "TextureManager.h"
#include "Parameters.h"

using namespace std;

class GameObject
{
public:
	
	virtual void draw(SDL_Renderer* renderer)= 0;
	virtual void update()= 0;
	virtual void clean()= 0;

protected:
	
	GameObject(const Parameters* parameters) {}
	virtual ~GameObject() {}

};