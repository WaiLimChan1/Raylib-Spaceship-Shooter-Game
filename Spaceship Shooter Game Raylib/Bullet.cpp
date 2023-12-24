#include "Bullet.h"
Bullet::Bullet() {}
Bullet::Bullet(float x, float y, float width, float height, float speed, Color color)
	: x(x), y(y), width(width), height(height), speed(speed), color(color) {}
float Bullet::getX() { return x; }
float Bullet::getY() { return y; }
float Bullet::getSpeed() { return speed; }
void Bullet::setX(float x) { this->x = x; }
void Bullet::setY(float y) { this->y = y; }

void Bullet::moveUp() { y -= speed; }
void Bullet::Draw() { DrawRectangle(x, y, width, height, color); }
Rectangle Bullet::getRec() { return Rectangle{ x, y, width, height }; }