#include "Vector2D.h"

void Vector2D::normalize() 
{
	float l = length();

	if (l > 0) 
	{
		(*this) *= 1 / l;
	}
}

Vector2D Vector2D::operator+(const Vector2D& v2) const
{
	return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}

Vector2D Vector2D::operator-(const Vector2D& v2) const
{
	return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}

Vector2D Vector2D::operator*(float scalar) const
{
	return Vector2D(scalar*m_x, scalar*m_y);
}

Vector2D Vector2D::operator/(float scalar) const
{
	return Vector2D(m_x/scalar, m_y/scalar);
}