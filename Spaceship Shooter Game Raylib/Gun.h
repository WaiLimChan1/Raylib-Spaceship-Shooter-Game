#pragma once
#include "Point.h"

class Gun {
private:
	Point point, firePoint;
	float width, height;
	Color color;
public:
	Gun();
	Gun(Point point, float width, float height, Color color);
	Point getPoint();
	Point getFirePoint();
	float getWidth();
	float getHeight();
	void setPointX(float x);
	void setPointY(float y);
	void Draw();
};
