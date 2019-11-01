// 18120172.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "CGame.h"

int main()
{
	CGame a; // tao game
	int order = 0; // lua chon cua nguoi dung
	drawMenu(order); // ve menu
	if (order != 3) {
		a.run(order); // chay game
	}
}

