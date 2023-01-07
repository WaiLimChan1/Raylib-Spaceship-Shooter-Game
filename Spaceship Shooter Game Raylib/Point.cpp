#include "Point.h"
Point::Point() {}
Point::Point(float x, float y) : x(x), y(y) {}
float Point::getX() { return x; }
float Point::getY() { return y; }
void Point::setX(float x) { this->x = x; }
void Point::setY(float y) { this->y = y; }