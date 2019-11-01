#pragma once
#include "pch.h"
#include "Point.h"
#include "CDraw.h"
#include <time.h>
#include <random>

#define pongChar 'o'
#define delChar ' '
enum dir {STOP = 0,LEFT = 1,UPLEFT = 2,DOWNLEFT = 3, RIGHT = 4, UPRIGHT =5,DOWNRIGHT = 6};

class CPong
{
private:
	Point curCor;
	Point spawnCor;
	enum dir direction;

public:
	void reset();
	void changDir(dir newDir);
	void Move();
	void initial();
	void randomDir() {
		direction = (dir)((rand() % 6)+1);
	}

	void draw(char c);

	int getCurX() {
		return curCor.getX();
	}
	int getCurY() {
		return curCor.getY();
	}
	dir getDir() {
		return direction;
	}
	void setCur(int x, int y) {
		curCor.setX(x);
		curCor.setY(y);
	}
	void setDir(int past) {
		direction = dir(past);
	}
	CPong();
	CPong(int x, int y);
	~CPong();
};

