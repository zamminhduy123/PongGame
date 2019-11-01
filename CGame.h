#pragma once
#include "pch.h"
#include <malloc.h>
#include <conio.h>
#include "graphic/graphics.h"
#include "CBar.h"
#include "CPong.h"
#include "Point.h"'
#include "CDraw.h"
#include <ctime>
#include <chrono>

#define resetButton 'r'

#define loadGameKey 10

#define pauseGame 'p'


#define WIDTH 60
#define HEIGHT 30


#define barLength 7

#define speedRange 5
#define defaultSpeed 50
#define minSpeed 5
#define botSpeed 0.02
#define winPoint 2
class CGame
{
private:
	CPong pong;
	CBar playerOne;
	CBar playerTwo;
	bool quit;
	int playerOneScore, playerTwoScore;
	int speed;
	int stage;
public:	
	void upScore(CBar player);
	void initial();
	void changeSpeed();
	void logic();
	void run(int);
	bool pause(int);
	void botPlayerMove();
	void displayScore();
	int setBotColor();
	void reset();
	void unPause();
	void botLevelUp();
	void saveGame(int choice);
	void loadGame(int&);
	void displayWinner(int );
	CGame();
	~CGame();
};

