#include "Gun.h"
Gun::Gun() {}
Gun::Gun(Point point, float width, float height, Color color) : point(point), width(width), height(height), color(color) { }
Point Gun::getPoint() { return point; }
Point Gun::getFirePoint()
{
	firePoint.setX(point.getX());
	firePoint.setY(point.getY());
	return firePoint;
}
float Gun::getWidth() { return width; }
float Gun::getHeight() { return height; }
void Gun::setPointX(float x) { point.setX(x); }
void Gun::setPointY(float y) { point.setY(y); }

void Gun::Draw() { DrawRectangle(point.getX(), point.getY(), width, height, color); }