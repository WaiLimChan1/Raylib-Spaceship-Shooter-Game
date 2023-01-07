#include "HitBox.h"
HitBox::HitBox() {}
HitBox::HitBox(float x, float y, float width, float height, Color color) : x(x), y(y), width(width), height(height), color(color) {}
float HitBox::getX() { return x; }
float HitBox::getY() { return y; }
float HitBox::getWidth() { return width; }
float HitBox::getHeight() { return height; }
void HitBox::setX(float x) { this->x = x; }
void HitBox::setY(float y) { this->y = y; }

void HitBox::Draw() { DrawRectangle(x, y, width, height, color); }
Rectangle HitBox::getRec()
{
	return Rectangle{ x, y, width, height };
}