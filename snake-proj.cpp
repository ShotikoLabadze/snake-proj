﻿#include <iostream>
#include<conio.h>
using namespace std;

bool youLose;
int x, y, getX, getY, score;
const int height = 20;
const int width = 30;
enum eMovement{STOP=0, UP,DOWN,RIGHT,LEFT};
eMovement mov;


void Setup() {
    youLose = false;
    mov = STOP;
    x = width / 2;
    y = height / 2;
    getX = rand() % width;
    getY = rand() % height;
    score = 0;
}
/*■■■■■■■■
* ■      ■
* ■      ■
* ■■■■■■■■
*/


void Draw() {
    system("cls");

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";

			if (i == y && j == x)
				cout << "O";

			else if (i == getY && j == getX)
				cout << "M";

			else
				cout << " ";

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	cout << "SCORE: " << score << endl;

}

void Input() {
	if (_kbhit())
	{
		switch (_getch()) {
		case 'q':
			youLose = true;
			break;
		case 'a':
			mov = LEFT;
			break;
		case 'd':
			mov = RIGHT;
			break;
		case 'w':
			mov = UP;
			break;
		case 's':
			mov = DOWN;
			break;
		}
	}
}

void Code() {
	
}


int main()
{
    Setup();
    while (!youLose)
    {
        Draw();
        Input();
        Code();
    }
    return 0;
}


