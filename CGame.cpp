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
	speed = defaultSpeed;
}

void CGame::changeSpeed()
{
	if (speed > minSpeed)
		speed -= speedRange;
	else
	{
		speed = 10;
	}
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
	if (pong.getCurX()+2 == playerTwo.getCurX()) {
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
		upScore(playerTwo);
	}
	// right
	if (pong.getCurX() == WIDTH - 2) {
		upScore(playerOne);
		pong.reset();

	}
}

void CGame::initial() {
	drawBoard();
	drawBar(2,HEIGHT/2);
	drawBar(WIDTH - 3, HEIGHT / 2);
	playerOne.initial(2, HEIGHT / 2);
	playerTwo.initial(WIDTH - 3, HEIGHT / 2);
	pong.initial();
	pong.draw(pongChar);	
	pong.randomDir();
}

void CGame::displayScore() {
	gotoXY(WIDTH/4 - 10, HEIGHT);
	std::cout << "Player One Score: " << playerOneScore << std::endl;
	gotoXY(3 * WIDTH / 4 - 10, HEIGHT);
	std::cout << "Player Two Score: " << playerTwoScore << std::endl;
}

void CGame::unPause() {
	system("cls");
	drawBoard();
	drawBar(playerOne.getCurX(),playerOne.getCurY());
	drawBar(playerTwo.getCurX(),playerTwo.getCurY());
	playerOne.initial(playerOne.getCurX(), playerOne.getCurY());
	playerTwo.initial(playerTwo.getCurX(), playerTwo.getCurY());
	pong.draw(pongChar);

}

void CGame::botPlayerMove() {
	if (pong.getCurX() > WIDTH / 2) {
		if (playerTwo.getCurY() - barLength / 2 > pong.getCurY()) {
			playerTwo.move(playerTwoUpControl);
		}
		else if (playerTwo.getCurY() + barLength / 2 < pong.getCurY()) {
			playerTwo.move(playerTwoDownControl);
		}
	}
}

void CGame::run(int choice) {
	char key;
	system("cls");
	gotoXY(1, 1);
	std::cout << "D";
	initial();
	while (1)
	{
		drawMiddleLine();
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case pauseGame:
				pause();
				unPause();
				break;
			case playerOneUpControl:
				playerOne.move(playerOneUpControl);
				break;
			case playerOneDownControl:
				playerOne.move(playerOneDownControl);
				break;
			case playerTwoUpControl:
				if (choice == 2)
					playerTwo.move(playerTwoUpControl);
				break;
			case playerTwoDownControl:
				if (choice == 2)
					playerTwo.move(playerTwoDownControl);
				break;
			case resetButton:
				pong.randomDir();
				break;
			default:
				break;
			}
		}
		if (choice == 1) {
			botPlayerMove();
		}
		pong.draw(delChar);
		logic();
		displayScore();
		pong.Move();
		pong.draw(pongChar);
		Sleep(speed);
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
	playerOneScore = 0;
	playerTwoScore = 0;
}




CGame::~CGame()
{
}
