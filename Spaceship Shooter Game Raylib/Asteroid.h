#pragma once
#include"raylib.h"
#include<cstdlib>
#include<time.h>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Asteroid {
private:
	float x, y, speedX, speedY, radius;
	Color color;
	string colorStr;
public:
	Asteroid();
	Asteroid(float x, float y, float speedX, float speedY, float radius, Color color, string colorStr);

	void setX(float x);
	void setY(float y);
	void setSpeedX(float speedX);
	void setSpeedY(float speedY);
	float getX();
	float getY();
	float getSpeedX();
	float getSpeedY();
	float getRadius();
	Color getColor();
	string getColorStr();

	void SetBall(float x, float y, float speedX, float speedY, float radius, Color color, string colorStr);
	void Draw();
};

