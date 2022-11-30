#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<cmath>
#include<cstdlib>
#include<random>

using namespace std;

random_device rd;
mt19937 gen(rd());

void gotoxy(int x, int y) {
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int random(int x, int y) {
	uniform_int_distribution<int> dis(x, y);
	return dis(gen);
}

