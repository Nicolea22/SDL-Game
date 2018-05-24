#pragma once
#include <string>
#include "Vector2D.h"

using namespace std;

const class Parameters 
{
public:

	/**
	* \brief - Parameters to initialize the game objects -
	* \x     - starting x position -
	* \y     - starting y position -
	* \width - texture's width     -
	* \height- texture's height    -
	* \textureID - texture's identification(file name) -
	*/      
	Parameters(float x, float y, int width, int height, string textureID) : 
		       m_position(x, y), m_width(width), m_height(height), m_textureID(textureID) {}

	float get_x() const { return m_position.get_comp_x(); };
	float get_y() const { return m_position.get_comp_y(); };

	float get_vx() const { return m_velocity.get_comp_x(); };
	float get_vy() const { return m_velocity.get_comp_y(); };

	int get_width() const { return m_width; };
	int get_height() const { return m_height; };

	string get_textureID() const { return m_textureID; };

private:

	Vector2D m_position;
	Vector2D m_velocity;

	int m_width;
	int m_height;

	string m_textureID;
};