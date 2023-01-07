#pragma once
#include "Point.h";
class HitBox {
private:
	float x, y;
	float width, height;
	Color color;
public:
	HitBox();
	HitBox(float x, float y, float width, float height, Color color);

	float getX();
	float getY();
	float getWidth();
	float getHeight();
	void setX(float x);
	void setY(float y);

	void Draw();
	Rectangle getRec();
};
