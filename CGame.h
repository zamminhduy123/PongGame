#pragma once
#include "pch.h"
#include <malloc.h>
#include <conio.h>
#include "graphic/graphics.h"
#include "CBar.h"
#include "CPong.h"
#include "Point.h"'

#define resetButton 'r'



#define pauseGame 'p'

#define WIDTH 60
#define HEIGHT 30


#define barLength 7

#define speedRange 5
#define defaultSpeed 75
#define minSpeed 25

class CGame
{
private:
	CPong pong;
	CBar playerOne;
	CBar playerTwo;
	bool quit;
	int playerOneScore, playerTwoScore;
	int speed;

public:	
	void upScore(CBar player);
	void initial();
	void changeSpeed();
	void logic();
	void run(int);
	void pause();
	void botPlayerMove();
	void displayScore();
	void unPause();
	CGame();
	~CGame();
};

