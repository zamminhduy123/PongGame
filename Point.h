#pragma once
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	double distance(Point);
	Point();
	Point(int corX, int corY);
	~Point();
};

