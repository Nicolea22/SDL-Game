#pragma once
#include <math.h>

class Vector2D
{
public:

	Vector2D() {}
	Vector2D(float x, float y) : m_x(x), m_y(y) {}

	float get_comp_x() const { return m_x; };
	float get_comp_y() const { return m_y; };

	void set_comp_x(float x) { m_x = x; }
	void set_comp_y(float y) { m_y = y; }

	float length() { return sqrt(m_x * m_x + m_y * m_y); };

	double get_angle_arcos();
	double get_angle_arcsen();
	double get_angle_arctg();

	void normalize();
	Vector2D desnormalize();

	Vector2D operator+(const Vector2D& v2) const;
	Vector2D operator-(const Vector2D& v2) const;
	Vector2D operator*(float scalar) const;
	Vector2D operator/(float scalar) const;

	Vector2D& operator = (float scalar) 
	{
		m_x = scalar;
		m_y = scalar;

		return *this;
	}

	Vector2D& operator= (const Vector2D v2)
	{
		m_x = v2.m_x;
		m_y = v2.m_y;

		return *this;
	}

	friend Vector2D& operator += (Vector2D& v1, const Vector2D& v2) 
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	friend Vector2D& operator -= (Vector2D& v1, const Vector2D& v2) 
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;

		return v1;
	}

	Vector2D& operator *= (float scalar) 
	{
		m_x *= scalar;
		m_y *= scalar;

		return *this;
	}

	Vector2D operator /= (float scalar) 
	{
		m_x /= scalar;
		m_y /= scalar;

		return *this;
	}


private:

	float m_x;
	float m_y;

};