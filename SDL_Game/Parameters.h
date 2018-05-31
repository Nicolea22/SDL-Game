#pragma once
#include <string>
#include "Vector2D.h"

using namespace std;

const class Parameters 
{
public:

	/**
	* \brief - Parameters to initialize the game objects -
	*
	* \x     - starting x position -
	* \y     - starting y position -
	* \width - texture's width     -
	* \height- texture's height    -
	* \textureID - texture's identification(file name) -
	* \num_frames - frames amount -
	*
	*/      
	Parameters(float x, float y, int width, int height,  string textureID, int num_frames, int call_backID = 0) :
		       m_position(x, y),
			   m_width(width),
			   m_height(height), 
		       m_textureID(textureID),
			   m_num_frames(num_frames),
			   m_call_back_id(call_backID)
	{}

	float get_x() const { return m_position.get_comp_x(); };
	float get_y() const { return m_position.get_comp_y(); };

	Vector2D get_pos() const { return m_position; };

	int get_width() const { return m_width; };
	int get_height() const { return m_height; };

	string get_textureID() const { return m_textureID; };

	int get_num_frames() const { return m_num_frames; };

	int get_call_back_id() const { return m_call_back_id; };

private:

	const Vector2D m_position;

	const int m_width;
	const int m_height;

	const int m_num_frames;

	const int m_call_back_id;

	const string m_textureID;
};