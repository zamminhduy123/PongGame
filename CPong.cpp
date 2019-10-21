#include "pch.h"
#include "CPong.h"

#define WIDTH 60
#define HEIGHT 30

void CPong::reset() {
	curCor.setX(spawnCor.getX());
	curCor.setY(spawnCor.getY());
	direction = STOP;
}

void CPong::changDir(dir newDir)
{
	direction = newDir;
}

void CPong::initial() {
	spawnCor.setX(WIDTH / 2 - 1);
	spawnCor.setY(HEIGHT / 2 - 1);
	curCor = spawnCor;
}

void CPong::Move()
{
	switch (direction) {
	case STOP:
		break;
	case LEFT:
		curCor.setX(curCor.getX()-1);
		break;
	case RIGHT:
		curCor.setX(curCor.getX() + 1);
		break;
	case UPLEFT:
		curCor.setX(curCor.getX() - 1);
		curCor.setY(curCor.getY() - 1);
		break;
	case DOWNLEFT:
		curCor.setX(curCor.getX() - 1);
		curCor.setY(curCor.getY() + 1);
		break;
	case UPRIGHT:
		curCor.setX(curCor.getX() + 1);
		curCor.setY(curCor.getY() - 1);
		break;
	case DOWNRIGHT:
		curCor.setX(curCor.getX() + 1);
		curCor.setY(curCor.getY() + 1);
		break;
	}
}

void CPong::draw(char c)
{
	gotoXY(curCor.getX(), curCor.getY());
	std::cout << c;
}



CPong::CPong() {
	direction = STOP;
	curCor.setX(WIDTH / 2);
	curCor.setY(HEIGHT / 2);
}

CPong::CPong(int x,int y)
{
	curCor.setX(x);
	curCor.setY(y);
	spawnCor.setX(x);
	spawnCor.setY(y);
	direction = STOP;
}


CPong::~CPong()
{
}
