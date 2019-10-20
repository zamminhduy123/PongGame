#include "pch.h"
#include "CBar.h"

void CBar::reset() {
	curCor.setX(spawnCor.getX());
	curCor.setY(spawnCor.getY());
}

void CBar::initial(int x,int y) {
	spawnCor.setX(x);
	spawnCor.setY(y);
	curCor = spawnCor;
	length = barLength;
}

void CBar::moveUp() {
	curCor.setY(curCor.getY() - 1);
}
void CBar::moveDown() {
	curCor.setY(curCor.getY() + 1);
}

bool CBar::zoneCheck() {
	if ((getCurY() + getLength() / 2 == HEIGHT - 2) || (getCurY() - getLength() / 2 == 2)) {
		return false;
	}
	return true;
}

void CBar::move(char movingKey) {
	if (zoneCheck()) {
		if (movingKey == playerOneUpControl || movingKey == playerTwoUpControl) {
			gotoXY(getCurX(), getCurY() + getLength() / 2);
			std::cout << " ";
			moveUp();
			gotoXY(getCurX(), getCurY() - getLength() / 2);
			std::cout << barChar;
		}
		else {
			gotoXY(getCurX(), getCurY() - getLength() / 2);
			std::cout << " ";
			moveDown();
			gotoXY(getCurX(), getCurY() + getLength() / 2);
			std::cout << barChar;
		}
	}
}


CBar::CBar(int x, int y,int newLength)
{
	curCor.setX(x);
	curCor.setY(y);
	spawnCor.setX(x);
	spawnCor.setY(y);
	length = newLength;
}

CBar::CBar()
{
	length = 0;
}


CBar::~CBar()
{
}
