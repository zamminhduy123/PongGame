#include "pch.h"
#include "CBar.h"


// tra ve vi tri ban dau
void CBar::reset() {
	curCor.setX(spawnCor.getX());
	curCor.setY(spawnCor.getY());
}

// khoi tao 
void CBar::initial(int x,int y) {
	spawnCor.setX(x);
	spawnCor.setY(y);
	curCor = spawnCor;
	length = barLength;
}

// di len
void CBar::moveUp() {
	curCor.setY(curCor.getY() - 1);
}

// di xuong
void CBar::moveDown() {
	curCor.setY(curCor.getY() + 1);
}

// check xem co di len duoc phia tren khong
bool CBar::upCheck() {
	if ((getCurY() - getLength() / 2 == 2)) {
		return false;
	}
	return true;
}
// check xem co di xuong duoi duoc khong
bool CBar::downCheck() {
	if ((getCurY() + getLength() / 2 == HEIGHT - 2)) {
		return false;
	}
	return true;
}

// di chuyen
void CBar::move(char movingKey) {
	// ham di chuyen len xuong bang cac xoa 1 thanh o huong nguoc lai va ve 1 thanh moi o huong di chuyen
		if (movingKey == playerOneUpControl || movingKey == playerTwoUpControl) {
			if (upCheck()) {
				gotoXY(getCurX(), getCurY() + getLength() / 2);
				std::cout << " ";
				moveUp();
				gotoXY(getCurX(), getCurY() - getLength() / 2);
				std::cout << barChar;
			}
		}
		else {
			if (downCheck()) {
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
