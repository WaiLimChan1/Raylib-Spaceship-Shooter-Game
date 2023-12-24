#pragma once
#include "Point.h";
class Bullet {
private:
	float x, y, width, height, speed;
	Color color;
public:
	Bullet();
	Bullet(float x, float y, float width, float height, float speed, Color color);
	float getX();
	float getY();
	float getSpeed();
	void setX(float x);
	void setY(float y);

	void moveUp();
	void Draw();
	Rectangle getRec();
};
