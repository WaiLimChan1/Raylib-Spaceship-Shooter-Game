#pragma once
#include "Gun.h"
#include "HitBox.h"
class SpaceShip {
private:
	Point leftPoint, centerPoint, rightPoint;
	Gun leftGun, rightGun;
	float speedX, speedY;
	Color color;
	float width, height;
	HitBox upperHitbox, lowerHitbox;
public:
	SpaceShip();
	SpaceShip(Point leftPoint, Point centerPoint, Point rightPoint, Gun leftGun, Gun rightGun, float speedX, float speedY, Color color);
	Point getLeftPoint();
	Point getCenterPoint();
	Point getRightPoint();
	Gun getLeftGun();
	Gun getRightGun();
	float getSpeedX();
	float getSpeedY();
	HitBox getLowerHitBox();
	HitBox getUpperHitBox();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void Draw();
};

