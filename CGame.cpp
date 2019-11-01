#include "pch.h"
#include "CGame.h"

// Ham + diem moi khi banh cham vach va reset lai banh va speed
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

// thay doi speed moi khi banh cham vao thanh choi
void CGame::changeSpeed()
{
	if (speed > minSpeed)
		speed -= speedRange;
	else
	{
		speed = minSpeed;
	}
}

void CGame::logic() {
	// bar 1
	if (pong.getCurX()-1 == playerOne.getCurX()) {	// xet x cua banh neu nhu chuan bi cham vao thanh choi thi chay for de vet y cua thanh choi so voi y cua banh
		for (int i = 0; i < barLength; i++) {
			if (pong.getCurY() == playerOne.getCurY() - barLength/2 + i) {
				pong.changDir((dir)(rand() % 3 + 4));
			}
		}
		changeSpeed(); // thay doi speed neu nhu cham vao thanh choi
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
	// neu dung vao thanh tren thi bat lai theo vat li
	if (pong.getCurY()-1 <= 2) {
		pong.changDir((pong.getDir() == UPRIGHT) ? DOWNRIGHT : DOWNLEFT);
	}
	// thanh duoi
	if (pong.getCurY()+1 == HEIGHT - 2) {
		pong.changDir((pong.getDir() == DOWNRIGHT) ? UPRIGHT : UPLEFT);
	}
	// neu dung vao thanh trai hoac phai thi + diem cho nguoi choi
	if (pong.getCurX() == 1) {
		upScore(playerTwo);
		stage = 1; // tra con bot ve level 1
		gotoXY(65, 15);
		cout << "Press R to continue the Game";
		drawBar(playerTwo.getCurX(), playerTwo.getCurY());
		drawBar(playerOne.getCurX(), playerOne.getCurY());
	}
	// right
	if (pong.getCurX() == WIDTH - 2) {
		upScore(playerOne);
		stage = 1;
		gotoXY(65, 15);
		cout << "Press R to continue the Game";
		drawBar(playerTwo.getCurX(), playerTwo.getCurY());
		drawBar(playerOne.getCurX(), playerOne.getCurY());
	}
}

// khoi tao game
void CGame::initial() {
	drawBoard(); // ve ban choi
	drawBar(2,HEIGHT/2); // ve thanh choi dau tien
	drawBar(WIDTH - 3, HEIGHT / 2); // ve thanh choi thu 2
	playerOne.initial(2, HEIGHT / 2);  // khoi tao nguoi choi 1
	playerTwo.initial(WIDTH - 3, HEIGHT / 2); // khoi tao nguoi choi 2
	pong.initial(); // khoi tao banh
	pong.draw(pongChar);	 // ve banh
	pong.randomDir(); // cho banh 1 huong chay ngau nhien
}

// hien thi diem tren man hinh
void CGame::displayScore() {
	gotoXY(WIDTH/4 - 10, HEIGHT);
	std::cout << "Player One Score: " << playerOneScore << std::endl;
	gotoXY(3 * WIDTH / 4 - 10, HEIGHT);
	std::cout << "Player Two Score: " << playerTwoScore << std::endl;
}

// Tiep tuc choi khi pause
void CGame::unPause() {
	system("cls");
	drawBoard();
	drawBar(playerOne.getCurX(),playerOne.getCurY());
	drawBar(playerTwo.getCurX(),playerTwo.getCurY());
	playerOne.initial(playerOne.getCurX(), playerOne.getCurY());
	playerTwo.initial(playerTwo.getCurX(), playerTwo.getCurY());
	pong.draw(pongChar);

}

//ham dieu khien bot
void CGame::botPlayerMove() {
		if (pong.getCurX() > WIDTH / 2 && pong.getDir() >= 4) {
			if (playerTwo.getCurY() - barLength / 2 > pong.getCurY()) {
				playerTwo.move(playerTwoUpControl);
			}
			else if (playerTwo.getCurY() + barLength / 2 < pong.getCurY()) {
				playerTwo.move(playerTwoDownControl);
			}
	}
	//if (pong.getCurX() < WIDTH / 2) {
	//	if (playerOne.getCurY() - barLength / 2 > pong.getCurY()) {
	//		playerOne.move(playerTwoUpControl);
	//	}
	//	else if (playerOne.getCurY() + barLength / 2 < pong.getCurY()) {
	//		playerOne.move(playerTwoDownControl);
	//	}
	//}
}

void CGame::reset() {
	stage = 1;
	playerOne.reset();
	playerTwo.reset();
	playerOneScore = 0;
	playerTwoScore = 0;
	pong.reset();
}


//ham game chay
void CGame::run(int choice) {
	system("cls");
	if (choice == loadGameKey) {
		loadGame(choice);
	}
	else {
		initial();
	}
	char key;
	// ham lay thoi gian he thong de xu ly level cho bot
	auto start = std::chrono::system_clock::now();
	auto startGame = std::chrono::system_clock::now();
	double botRunTime = botSpeed;
	stage = 1;
	while (1)
	{
			
		drawMiddleLine(); // ve thanh o giua, vi khi banh cham vao thanh co the mat thanh nen can ve lai
		if (_kbhit()) { // neu co nhan input tu ban phim 
			key = _getch(); // lay phim
			switch (key) {
			case pauseGame:
				if (pause(choice)) {
					exit(0);
				};
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
				for (int i = 0; i < 29; i++) {
					gotoXY(65+i, 15);
					cout << " ";
				}
				pong.randomDir();
				stage = 1;
				start = std::chrono::system_clock::now();
				break;
			default:
				break;
			}
		}
		auto end = std::chrono::system_clock::now();
		// tinh toan thoi gian choi de tang level cho bot va thoi gian bot duoc phep di chuyen
		std::chrono::duration<double> elapsed_seconds = end - start;
		if (elapsed_seconds.count() >= botRunTime) {
			if (choice == 1) {
				botPlayerMove();
				
			}
			start = std::chrono::system_clock::now();
			std::chrono::duration<double> stageTime = end - startGame;
			if (stageTime.count() >= 5) {
				startGame = std::chrono::system_clock::now();
				stage++;
				if (rand() % 2 == 0) {
					botRunTime -= 0.01;
				}
				else {
					botRunTime += 0.01;
				}
			}
		}
		botLevelUp();
		

		pong.draw(delChar); // xoa banh o vi tri hien tai
		logic(); //xet tinh logic neu banh co va cham
		displayScore(); // hien thi diem
		
		
		if (playerOneScore == winPoint){ // xet diem chien thang
			system("cls");
			displayWinner(1);
			_getch();
			if (!pause(choice)) {
				reset();
			}
			else {
				exit(0);
			}
		}
		else  if (playerTwoScore == winPoint) {
			system("cls");
			displayWinner(2);
			_getch();
			if (!pause(choice)) {
				reset();
			}
			else {
				exit(0);
			}
		}
		
		// banh di chuyen
		pong.Move();
		// ve banh
		pong.draw(pongChar);
		// ham speed de thay doi toc do banh 
		Sleep(speed);
	}
}
// hien thi neu 1 trong 2 nguoi choi dat diem chien thang
void CGame::displayWinner(int player) {
	drawWinner(player);
}

// day la ham luu game
void CGame::saveGame(int choice) {
	freopen("output.txt", "wt", stdout);// mo file 
	// luu cac thong tin can thiet
	std::cout << playerOne.getCurX() << " " << playerOne.getCurY() << std::endl;
	std::cout << playerTwo.getCurX() << " " << playerTwo.getCurY() << std::endl;
	std::cout << pong.getCurX() << " " << pong.getCurY() << " " << pong.getDir() << std::endl;
	std::cout << choice << " ";
	std::cout << stage;
	freopen("CON", "wt", stdout);
	// chuyeen lai input sang console
}

// thay doi mau cua bot o moi level
int CGame::setBotColor() {
	switch (stage) {
	case 1:
		return 7; // mau trang
	case 2: 
		return 10; // xanh la
	case 3:
		return 11; // xanh duong
	case 4:
		return 12; // do
	default:
		break;
	}
	return 12;
}
// tang level cho bot bang cach doi mau
void CGame::botLevelUp() {
	setColor(0, setBotColor());
	drawBar(playerTwo.getCurX(), playerTwo.getCurY());
	setColor(0, 7);
}

// ham mo lai game da luu
void CGame::loadGame(int &choice) {
	freopen("input.txt", "rt", stdin);
	int x, y;
	std::cin >> x >> y;
	playerOne.setCur(x, y);
	std::cin >> x >> y;
	playerTwo.setCur(x, y);
	std::cin >> x >> y;
	pong.setCur(x, y);
	int direct;
	std::cin >> direct;
	pong.setDir(direct);
	std::cin >> choice;
	std::cin >> stage;
	freopen("CON", "rt", stdin);
	drawBoard();
	drawBar(playerOne.getCurX(),playerOne.getCurY());
	drawBar(playerTwo.getCurX(),playerTwo.getCurY());
	playerOne.initial(playerOne.getCurX(), playerOne.getCurY());
	playerTwo.initial(playerTwo.getCurX(), playerTwo.getCurY());
	pong.draw(pongChar);
}
// ham dung game
bool CGame::pause(int choice) {
	system("cls");
	if (drawPause() == 1) {
		unPause();
		return false;
	}
	else {
		saveGame(choice);
		return true;
	}
}



CGame::CGame()
{
	srand(time(NULL));
	speed = defaultSpeed;
	quit = false;
	playerOneScore = 0;
	playerTwoScore = 0;
	stage = 1;
}




CGame::~CGame()
{
}
