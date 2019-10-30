// 18120172.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "CGame.h"

int main()
{
	CGame a;
	int order = 0;
	drawMenu(order);
	if (order != 3) {
		a.run(order);
	}
}

