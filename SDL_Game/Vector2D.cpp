#include "Vector2D.h"
# define M_PI 3.14159265358979323846

double Vector2D::get_angle_arcsen()
{
	if (m_y != 0)
	{
		return asin(m_y / length()) * 180 / M_PI;
	}
	return 0;
}

double Vector2D::get_angle_arcos()
{
	if (m_x != 0)
	{
		return acos(m_x / length()) * 180 / M_PI;
	}
	return 0;
}


double Vector2D::get_angle_arctg() 
{
	if (m_x != 0 && m_y != 0) 
	{
		return atan(m_y/m_x) * 180 / M_PI;
	}
	return 0;
}

Vector2D Vector2D::desnormalize() 
{
	float l = length();

	if (l > 0) 
	{
		return (*this) *= l;
	}

	return (*this);
}

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