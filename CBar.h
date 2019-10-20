#pragma once
#include "pch.h"
#include "Point.h"
#include "CDraw.h"

#define space 3

#define KEY_UP 72
#define KEY_DOWN 80

#define playerOneUpControl 'w'
#define playerOneDownControl 's'
#define playerTwoUpControl KEY_UP
#define playerTwpDownControl KEY_DOWN
#define barLength 7
#define WIDTH 60
#define HEIGHT 30

#define barChar '|'

class CBar
{
private:
	Point curCor;
	Point spawnCor;
	int length;
public:
	void moveUp();
	void moveDown();
	void move(char);
	void reset();
	void initial(int,int);
	bool zoneCheck();

	int getCurX() {
		return curCor.getX();
	}
	int getCurY() {
		return curCor.getY();
	}
	int getLength() {
		return length;
	}
	CBar(int x, int y,int);
	CBar();
	~CBar();
};

