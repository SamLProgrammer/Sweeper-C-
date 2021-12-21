#pragma once
#include <cmath>
class Vec2DI {
public:
	Vec2DI() = default;
	Vec2DI(int in_x, int in_y);
	bool operator==(Vec2DI& rh_vec) const;
	Vec2DI operator+(Vec2DI& rh_vec) const;
	Vec2DI& operator+=(Vec2DI& rh_vec);
	Vec2DI operator*(int scalar) const;
	Vec2DI& operator*=(int scalar);
	Vec2DI operator-(Vec2DI& rh_vec) const;
	Vec2DI& operator-=(Vec2DI& rh_vec);
	int length() const;
	int sqrdLength() const;
	Vec2DI& normalize();
	Vec2DI getNormalized() const;
	int getX() const;
	int getY() const;
private:
	int x;
	int y;
};
