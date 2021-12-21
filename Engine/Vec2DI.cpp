#include "Vec2DI.h"

Vec2DI::Vec2DI(int in_x, int in_y)
	:
	x(in_x),
	y(in_y)
{
}

bool Vec2DI::operator==(Vec2DI& rh_vec) const
{
	return x == rh_vec.x && y == rh_vec.y;
}

Vec2DI Vec2DI::operator+(Vec2DI& rh_vec) const
{

	return Vec2DI(x + rh_vec.x, y + rh_vec.y);
}

Vec2DI& Vec2DI::operator+=(Vec2DI& rh_vec)
{
	return *this = *this + rh_vec;
}

Vec2DI Vec2DI::operator*(int scalar) const
{
	return Vec2DI(x * scalar, y * scalar);
}

Vec2DI& Vec2DI::operator*=(int scalar)
{
	return *this = *this * scalar;
}

Vec2DI Vec2DI::operator-(Vec2DI& rh_vec) const
{
	return Vec2DI(x - rh_vec.x, y - rh_vec.y);
}

Vec2DI& Vec2DI::operator-=(Vec2DI& rh_vec)
{
	return *this = *this - rh_vec;
}

int Vec2DI::length() const
{
	return std::sqrt(sqrdLength());
}

int Vec2DI::sqrdLength() const
{
	return x * x + y * y;
}

Vec2DI& Vec2DI::normalize()
{
	return *this = getNormalized();
}

Vec2DI Vec2DI::getNormalized() const
{
	if (length() > 0) {
		return *this * (1.0f / length());
	}
	return *this;
}

int Vec2DI::getX() const
{
	return x;
}

int Vec2DI::getY() const
{
	return y;
}
