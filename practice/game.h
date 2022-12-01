#pragma once
#include "Console.h"
using namespace std;

int map[40][20] = { 0, };
int Emap[40][20] = { 0, };

bool Set = true;
bool Game = true;
bool menu = true;
bool Start = true;

int flag = 80;
int Block = 800;

int px = 0;
int py = 0;

void DrawBlock();
void GetKey();
void DrawFlag();
void GameOver();
void Menu();

void DrawEmpty(int x, int y) {
	switch (map[x][y]) {
	case 0:
		gotoxy(x, y);
		cout << "ㅤ";
		Block--;
		Emap[x][y] = 1;
		break;
	case 1:
		gotoxy(x, y);
		cout << "１";
		Block--;
		Emap[x][y] = 1;
		return;
	case 2:
		gotoxy(x, y);
		cout << "２";
		Block;
		Emap[x][y] = 1;
		return;
	case 3:
		gotoxy(x, y);
		cout << "３";
		Block--;
		Emap[x][y] = 1;
		return;
	case 4:
		gotoxy(x, y);
		cout << "４";
		Block--;
		Emap[x][y] = 1;
		return;
	case 5:
		gotoxy(x, y);
		cout << "５";
		Block--;
		Emap[x][y] = 1;
		return;
	case 6:
		gotoxy(x, y);
		cout << "６";
		Block--;
		Emap[x][y] = 1;
		return;
	case 7:
		gotoxy(x, y);
		cout << "７";
		Block--;
		Emap[x][y] = 1;
		return;
	case 8:
		gotoxy(x, y);
		cout << "８";
		Block--;
		Emap[x][y] = 1;
		return;
	default:
		break;
	}
	if (x != 0 && map[x - 1][y] != 10 && Emap[x - 1][y] == 0)DrawEmpty(x - 1, y);
	if (x != 0 && y != 0 && map[x - 1][y - 1] != 10 && Emap[x - 1][y - 1] == 0)DrawEmpty(x - 1, y - 1);
	if (y != 0 && map[x][y - 1] != 10 && Emap[x][y - 1] == 0)DrawEmpty(x, y - 1);
	if (x != 39 && y != 0 && map[x + 1][y - 1] != 10 && Emap[x + 1][y - 1] == 0)DrawEmpty(x + 1, y - 1);
	if (x != 39 && map[x + 1][y] != 10 && Emap[x + 1][y] == 0)DrawEmpty(x + 1, y);
	if (x != 39 && y != 19 && map[x + 1][y + 1] != 10 && Emap[x + 1][y + 1] == 0)DrawEmpty(x + 1, y + 1);
	if (y != 19 && map[x][y + 1] != 10 && Emap[x][y + 1] == 0)DrawEmpty(x, y + 1);
	if (x != 0 && y != 19 && map[x - 1][y + 1] != 10 && Emap[x - 1][y + 1] == 0)DrawEmpty(x - 1, y + 1);
}
void SetMine() {
	for (int i = 0; i < 80; i++) {
		int _x = random(0, 39);
		int _y = random(0, 19);
		if (map[_x][_y] != 10) {
			if (map[_x][_y - 1] == 10 && map[_x + 1][_y - 1] == 10 && map[_x + 1][_y] == 10 && map[_x + 1][_y + 1] == 10
				&& map[_x][_y + 1] && map[_x - 1][_y + 1] == 10 && map[_x - 1][_y] == 10 && map[_x - 1][_y - 1] == 10) {
				i--;
			}
			else {
				map[_x][_y] = 10;
				if (_x != 39 && map[_x + 1][_y] != 10)map[_x + 1][_y]++;
				if (_x != 39 && _y != 19 && map[_x + 1][_y+1] != 10)map[_x + 1][_y + 1]++;
				if (_y != 19 && map[_x][_y+1] != 10)map[_x][_y + 1]++;
				if (_x != 0 && _y != 19 && map[_x - 1][_y+1] != 10)map[_x - 1][_y + 1]++;
				if (_x != 0 && map[_x - 1][_y] != 10)map[_x - 1][_y]++;
				if (_x != 0 && _y != 0 && map[_x - 1][_y-1] != 10)map[_x - 1][_y - 1]++;
				if (_y != 0 && map[_x][_y-1] != 10)map[_x][_y - 1]++;
				if (_x != 39 && _y != 0 && map[_x + 1][_y-1] != 10)map[_x + 1][_y - 1]++;
			}
		}
		else i--;
	}
}
void SetBlock() {
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
	gotoxy(20, 21);
	cout << "깃발 :";
	gotoxy(24, 21);
	cout << flag;
}
void GetKey() {
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		if (px != 0) {
			gotoxy(--px, py);
			Sleep(100);
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		if (px != 39) {
			gotoxy(++px, py);
			Sleep(100);
		}
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		if (py != 0) {
			gotoxy(px, --py);
			Sleep(100);
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		if (py != 19) {
			gotoxy(px, ++py);
			Sleep(100);
		}
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		if (Emap[px][py] == 0){
			DrawBlock();
			Emap[px][py] = 1;
			Sleep(200);
		}
	}
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
		
		DrawFlag();
		Sleep(200);
	}
}
void DrawBlock() {
	if (Start) {
		if (map[px][py] == 10) {
			map[px][py] = 0;
			if (px != 39 && map[px + 1][py] != 10)map[px + 1][py]--;
			if (px != 39 && py != 19 && map[px + 1][py + 1] != 10)map[px + 1][py + 1]--;
			if (py != 19 && map[px][py + 1] != 10)map[px][py + 1]--;
			if (px != 0 && py != 19 && map[px - 1][py + 1] != 10)map[px - 1][py + 1]--;
			if (px != 0 && map[px - 1][py] != 10)map[px - 1][py]--;
			if (px != 0 && py != 0 && map[px - 1][py - 1] != 10)map[px - 1][py - 1]--;
			if (py != 0 && map[px][py - 1] != 10)map[px][py - 1]--;
			if (px != 39 && py != 0 && map[px + 1][py - 1] != 10)map[px + 1][py - 1]--;
		}
		if (px != 39 && map[px + 1][py] == 10)map[px][py]++;
		if (px != 39 && py != 19 && map[px + 1][py + 1] == 10)map[px][py]++;
		if (py != 19 && map[px][py + 1] == 10)map[px][py]++;
		if (px != 0 && py != 19 && map[px - 1][py + 1] == 10)map[px][py]++;
		if (px != 0 && map[px - 1][py] == 10)map[px][py]++;
		if (px != 0 && py != 0 && map[px - 1][py - 1] == 10)map[px][py]++;
		if (py != 0 && map[px][py - 1] == 10)map[px][py]++;
		if (px != 39 && py != 0 && map[px + 1][py - 1] == 10)map[px][py]++;
		Start = false;
	}
	gotoxy(px, py);
	if (Emap[px][py] == 2) return;
	switch (map[px][py]) {
	case 0:
		DrawEmpty(px, py);
		break;
	case 10:
		cout << "※";
		Sleep(1000);
		GameOver();
		//game over
		return;
	case 1:
		cout << "１";
		Block--;
		break;
	case 2:
		cout << "２";
		Block--;
		break;
	case 3:
		cout << "３";
		Block--;
		break;
	case 4:
		cout << "４";
		Block--;
		break;
	case 5:
		cout << "５";
		Block--;
		break;
	case 6:
		cout << "６";
		Block--;
		break;
	case 7:
		cout << "７";
		Block--;
		break;
	case 8:
		cout << "８";
		Block--;
		break;
	default:
		cout << map[px][py];
		break;
	}
	Emap[px][py] = 1;
	gotoxy(px, py);
}
void DrawFlag() {
	if (Emap[px][py] == 0 && flag > 0) {
		gotoxy(24, 21);
		cout << "     ";
		gotoxy(24, 21);
		cout << --flag;
		gotoxy(px, py);
		cout << "§";
		Emap[px][py] = 2;
	}
	else if (Emap[px][py] == 1) return;
	else if (Emap[px][py] == 2) {
		gotoxy(24, 21);
		cout << "     ";
		gotoxy(24, 21);
		cout << ++flag;
		gotoxy(px, py);
		cout << "□";
		Emap[px][py] = 0;
	}
	gotoxy(px, py);
}
void DrawAll() {
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 20; j++) {
			px = i;
			py = j;
			DrawBlock();
		}
	}
}
void GameOver() {
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[i][j] == 10) {
				gotoxy(i, j);
				cout << "※";
				Sleep(30);
			}
		}
	}
	Sleep(2000);
	system("cls");
	cout << "Game Over";
	Sleep(2000);
	system("cls");
	Game = false;
}
void PlayGame() {
	system("cls");
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 20; j++) {
			map[i][j] = 0;
			Emap[i][j] = 0;
		}
	}
	SetBlock();
	SetMine();
	gotoxy(0, 0);
	px = 0;
	py = 0;
	flag = 80;
	while (Game) {
		GetKey();
		if (Block == 80) {
			system("cls");
			cout << "PerFect!";
			Sleep(2000);
			Game = false;
		}
	}
	menu = true;
	Menu();
}
void Menu() {
	system("cls");
	int xx = 22;
	int yy = 20;
	gotoxy(20, 4);
	cout << "#     #  #####  ##   #  #####";
	gotoxy(20, 5);
	cout << "##   ##    #    # #  #  #";
	gotoxy(20, 6);
	cout << "# # # #    #    #  # #  #####";
	gotoxy(20, 7);
	cout << "#  #  #    #    #   ##  #";
	gotoxy(20, 8);
	cout << "#     #  #####  #    #  #####";
	gotoxy(xx+3, yy);
	cout << "게임 시작";
	gotoxy(xx+3, yy + 1);
	cout << "게임 종료";
	gotoxy(xx, yy);
	cout << "▶";
	while (menu) {
		if (GetAsyncKeyState(VK_UP) && yy == 21) {
			gotoxy(xx, yy);
			cout << "　";
			yy--;
			gotoxy(xx, yy);
			cout << "▶";
		}
		if (GetAsyncKeyState(VK_DOWN) && yy == 20) {
			gotoxy(xx, yy);
			cout << "　";
			yy++;
			gotoxy(xx, yy);
			cout << "▶";
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			if (yy == 20) {
				Game = true;
				menu = false;
				Sleep(200);
				PlayGame();
			}
			else if (yy == 21) {
				Game = false;
				menu = false;
				Sleep(200);
			}
		}
	}
}

