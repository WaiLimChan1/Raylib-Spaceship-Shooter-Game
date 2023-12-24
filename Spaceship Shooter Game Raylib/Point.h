#pragma once
#include"raylib.h"
#include<cstdlib>
#include<time.h>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Point {
private:
	float x, y;
public:
	Point();
	Point(float x, float y);
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
};
