#include "pch.h"
#include "Point.h"

double Point::distance(Point b) {
	double disX = x - b.getX();
	double disY = y - b.getY();
	return sqrt(disX*disX + disY * disY);
}

int Point::getX() {
	return x;
}
int Point::getY() {
	return y;
}

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int corX,int corY)
{
	x = corX;
	y = corY;
}


Point::~Point()
{
}
