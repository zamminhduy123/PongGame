#include "pch.h"
#include "CGame.h"

void CGame::upScore(CBar player) {
	if (player.getCurX() == playerOne.getCurX()) {
		playerOneScore++;
	}
	else {
		playerTwoScore++;
	}
	pong.reset();
}

void CGame::changeSpeed()
{
	if (speed >= 10)
		speed -= speedRange;
	else
		speed = minSpeed;
}

void CGame::logic() {
	// bar 1
	if (pong.getCurX()-1 == playerOne.getCurX()) {	// truoc khi trung` vao thanh choi
		for (int i = 0; i < barLength; i++) {
			if (pong.getCurY() == playerOne.getCurY() - barLength/2 + i) {
				pong.changDir((dir)(rand() % 3 + 4));
			}
		}
		changeSpeed();
	}
	// bar 2
	if (pong.getCurX()+1 == playerTwo.getCurX()) {
		for (int i = 0; i < barLength; i++) {
			if (pong.getCurY() == playerTwo.getCurY() - barLength/2 + i) {
				pong.changDir((dir)(rand() % 3 + 1));
			}
		}
		changeSpeed();
	}
	// top 
	if (pong.getCurY()-1 <= 2) {
		pong.changDir((pong.getDir() == UPRIGHT) ? DOWNRIGHT : DOWNLEFT);
	}
	// bot
	if (pong.getCurY()+1 == HEIGHT - 2) {
		pong.changDir((pong.getDir() == DOWNRIGHT) ? UPRIGHT : UPLEFT);
	}
	// left
	if (pong.getCurX() == 1) {
		pong.reset();
		upScore(playerOne);
	}
	// right
	if (pong.getCurX() == WIDTH - 2) {
		upScore(playerTwo);
		pong.reset();
	}
}

void CGame::initial() {
	drawBoard();
	drawBar();
	playerOne.initial(2, HEIGHT / 2);
	playerTwo.initial(WIDTH - 3, HEIGHT / 2);
	pong.initial();
	pong.draw(pongChar);	
	pong.randomDir();
}

void CGame::run() {
	char key;
	system("cls");
	initial();
	while (1)
	{
		pong.draw(delChar);
		logic();
		pong.Move();
		pong.draw(pongChar);
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case pauseGame:
				pause();
				break;
			case playerOneUpControl:
				playerOne.move(playerOneUpControl);
				break;
			case playerOneDownControl:
				playerOne.move(playerOneDownControl);
				break;
			case playerTwoUpControl:
				playerTwo.move(playerTwoUpControl);
				break;
			case playerTwpDownControl:
				playerTwo.move(playerTwpDownControl);
				break;
			case resetButton:
				pong.randomDir();
				break;
			default:
				break;
			}
		}
		Sleep(defaultSpeed);
	}
}

void CGame::pause() {
	system("pause");
}



CGame::CGame()
{
	srand(time(NULL));
	speed = defaultSpeed;
	quit = false;
}




CGame::~CGame()
{
}
