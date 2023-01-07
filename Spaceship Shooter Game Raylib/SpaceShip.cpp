#include "SpaceShip.h"
SpaceShip::SpaceShip() {}
SpaceShip::SpaceShip(Point leftPoint, Point centerPoint, Point rightPoint, Gun leftGun, Gun rightGun, float speedX, float speedY, Color color)
	: leftPoint(leftPoint), centerPoint(centerPoint), rightPoint(rightPoint), leftGun(leftGun), rightGun(rightGun), speedX(speedX), speedY(speedY), color(color)
{
	width = rightPoint.getX() - leftPoint.getX();
	height = rightPoint.getY() - centerPoint.getY();
	lowerHitbox = HitBox(leftPoint.getX(), leftPoint.getY() - height / 2, width, height / 2, GREEN);
	upperHitbox = HitBox(leftPoint.getX() + width / 4, centerPoint.getY(), width / 2, height / 2, GREEN);
}

Point SpaceShip::getLeftPoint() { return leftPoint; }
Point SpaceShip::getCenterPoint() { return centerPoint; }
Point SpaceShip::getRightPoint() { return rightPoint; }
Gun SpaceShip::getLeftGun() { return leftGun; }
Gun SpaceShip::getRightGun() { return rightGun; }
float SpaceShip::getSpeedX() { return speedX; }
float SpaceShip::getSpeedY() { return speedY; }
HitBox SpaceShip::getLowerHitBox() { return lowerHitbox; }
HitBox SpaceShip::getUpperHitBox() { return upperHitbox; }

void SpaceShip::moveLeft()
{
	leftPoint.setX(leftPoint.getX() - speedX * GetFrameTime());
	centerPoint.setX(centerPoint.getX() - speedX * GetFrameTime());
	rightPoint.setX(rightPoint.getX() - speedX * GetFrameTime());
	leftGun.setPointX(leftGun.getPoint().getX() - speedX * GetFrameTime());
	rightGun.setPointX(rightGun.getPoint().getX() - speedX * GetFrameTime());
	lowerHitbox.setX(lowerHitbox.getX() - speedX * GetFrameTime());
	upperHitbox.setX(upperHitbox.getX() - speedX * GetFrameTime());
	if (leftPoint.getX() < 0)
	{
		leftPoint.setX(0);
		centerPoint.setX(width / 2);
		rightPoint.setX(width);
		leftGun.setPointX(width / 4);
		rightGun.setPointX(width / 4 * 3);
		lowerHitbox.setX(0);
		upperHitbox.setX(width / 4);
	}
}
void SpaceShip::moveRight()
{
	leftPoint.setX(leftPoint.getX() + speedX * GetFrameTime());
	centerPoint.setX(centerPoint.getX() + speedX * GetFrameTime());
	rightPoint.setX(rightPoint.getX() + speedX * GetFrameTime());
	leftGun.setPointX(leftGun.getPoint().getX() + speedX * GetFrameTime());
	rightGun.setPointX(rightGun.getPoint().getX() + speedX * GetFrameTime());
	lowerHitbox.setX(lowerHitbox.getX() + speedX * GetFrameTime());
	upperHitbox.setX(upperHitbox.getX() + speedX * GetFrameTime());
	if (rightPoint.getX() > GetScreenWidth())
	{
		leftPoint.setX(GetScreenWidth() - width);
		centerPoint.setX(GetScreenWidth() - width / 2);
		rightPoint.setX(GetScreenWidth());
		leftGun.setPointX(GetScreenWidth() - width / 4 * 3);
		rightGun.setPointX(GetScreenWidth() - width / 4);
		lowerHitbox.setX(GetScreenWidth() - width);
		upperHitbox.setX(GetScreenWidth() - width / 4 * 3);
	}
}
void SpaceShip::moveUp()
{
	leftPoint.setY(leftPoint.getY() - speedY * GetFrameTime());
	centerPoint.setY(centerPoint.getY() - speedY * GetFrameTime());
	rightPoint.setY(rightPoint.getY() - speedY * GetFrameTime());
	leftGun.setPointY(leftGun.getPoint().getY() - speedY * GetFrameTime());
	rightGun.setPointY(rightGun.getPoint().getY() - speedY * GetFrameTime());
	lowerHitbox.setY(lowerHitbox.getY() - speedY * GetFrameTime());
	upperHitbox.setY(upperHitbox.getY() - speedY * GetFrameTime());
	if (centerPoint.getY() < 0)
	{
		leftPoint.setY(height);
		centerPoint.setY(0);
		rightPoint.setY(height);
		leftGun.setPointY(height - leftGun.getHeight());
		rightGun.setPointY(height - leftGun.getHeight());
		lowerHitbox.setY(height / 2);
		upperHitbox.setY(height - leftGun.getHeight());
	}
}
void SpaceShip::moveDown()
{
	leftPoint.setY(leftPoint.getY() + speedY * GetFrameTime());
	centerPoint.setY(centerPoint.getY() + speedY * GetFrameTime());
	rightPoint.setY(rightPoint.getY() + speedY * GetFrameTime());
	leftGun.setPointY(leftGun.getPoint().getY() + speedY * GetFrameTime());
	rightGun.setPointY(rightGun.getPoint().getY() + speedY * GetFrameTime());
	lowerHitbox.setY(lowerHitbox.getY() + speedY * GetFrameTime());
	upperHitbox.setY(upperHitbox.getY() + speedY * GetFrameTime());
	if (leftPoint.getY() > GetScreenHeight())
	{
		leftPoint.setY(GetScreenHeight());
		centerPoint.setY(GetScreenHeight() - height);
		rightPoint.setY(GetScreenHeight());
		leftGun.setPointY(GetScreenHeight() - leftGun.getHeight());
		rightGun.setPointY(GetScreenHeight() - leftGun.getHeight());
		lowerHitbox.setY(GetScreenHeight() - height / 2);
		upperHitbox.setY(GetScreenHeight() - leftGun.getHeight());
	}
}

void SpaceShip::Draw()
{
	leftGun.Draw();
	rightGun.Draw();
	DrawTriangle({ leftPoint.getX(), leftPoint.getY() }, { rightPoint.getX(), rightPoint.getY() }, { centerPoint.getX(), centerPoint.getY() }, WHITE);

	//Print hitboxes
	//lowerHitbox.Draw();
	//upperHitbox.Draw();
}