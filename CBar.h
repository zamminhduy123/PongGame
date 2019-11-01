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
#define playerTwoDownControl KEY_DOWN
#define barLength 7
#define WIDTH 60
#define HEIGHT 30

#define barChar '|'

class CBar
{
private:
	Point curCor; // vi tri hien tai
	Point spawnCor; // vi tri xuat hien
	int length; // do dai 
public:
	void moveUp();
	void moveDown();
	void move(char);
	void reset();
	void initial(int,int);
	bool upCheck();
	bool downCheck();

	int getCurX() {
		return curCor.getX();
	}
	int getCurY() {
		return curCor.getY();
	}
	int getLength() {
		return length;
	}
	void setCur(int x,int y) {
		curCor.setX(x);
		curCor.setY(y);
	}
	CBar(int x, int y,int);
	CBar();
	~CBar();
};

