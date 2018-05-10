#pragma once
#include <string>

using namespace std;

class Parameters 
{
public:

	Parameters(int x, int y, int width, int height, string textureID) : m_x(x), m_y(y),
				m_width(width), m_height(height), m_textureID(textureID) {}

	~Parameters();

	int get_x() { return m_x;  };
	int get_y() { return m_y; };

	int get_width() { return m_width; };
	int get_height() { return m_height; };

	string get_textureID() const { return m_textureID; };

private:

	int m_x;
	int m_y;

	int m_width;
	int m_height;

	string m_textureID;
};