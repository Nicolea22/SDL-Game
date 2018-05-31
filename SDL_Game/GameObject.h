#pragma once
#include <string>
#include <iostream>
#include "TextureManager.h"
#include "Parameters.h"

using namespace std;

class GameObject
{
public:
	
	virtual void draw()= 0;
	virtual void update()= 0;
	virtual void clean()= 0;

	virtual void load(const Parameters* parameters) = 0;

protected:

	GameObject() {}
	virtual ~GameObject() {}

};