#include "Asteroid.h"
Asteroid::Asteroid() { };

Asteroid::Asteroid(float x, float y, float speedX, float speedY, float radius, Color color, string colorStr)
	: x(x), y(y), speedX(speedX), speedY(speedY), radius(radius), color(color), colorStr(colorStr) { }

void Asteroid::setX(float x) { this->x = x; }
void Asteroid::setY(float y) { this->y = y; }
void Asteroid::setSpeedX(float speedX) { this->speedX = speedX; }
void Asteroid::setSpeedY(float speedY) { this->speedY = speedY; }
float Asteroid::getX() { return x; }
float Asteroid::getY() { return y; }
float Asteroid::getSpeedX() { return speedX; }
float Asteroid::getSpeedY() { return speedY; }
float Asteroid::getRadius() { return radius; }
Color Asteroid::getColor() { return color; }
string Asteroid::getColorStr() { return colorStr; }

void Asteroid::SetBall(float x, float y, float speedX, float speedY, float radius, Color color, string colorStr)
{
	this->x = x;
	this->y = y;
	this->speedX = speedX;
	this->speedY = speedY;
	this->radius = radius;
	this->color = color;
	this->colorStr = colorStr;
}
void Asteroid::Draw() { DrawCircle(x, y, radius, color); }