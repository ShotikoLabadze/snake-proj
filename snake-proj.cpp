#include <iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

bool youLose;
int x, y, getX, getY, score;
const int height = 20;
const int width = 30;
enum eMovement{STOP=0, UP,DOWN,RIGHT,LEFT};
eMovement mov;
int tailX[50], tailY[50];
int tailLength;


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

			else {
					bool print = false;
				for (int z = 0; z < tailLength; z++)
				{
					if (tailX[z] == j && tailY[z] == i) {
						print = true;
						cout << "o";
					}
				}

				if (!print)
				{
					cout << " ";
				}
			}

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
	int endX = tailX[0];
	int endY = tailY[0];
	int end2X, end2Y;

	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < tailLength; i++) {
		end2X = tailX[i];
		end2Y = tailY[i];

		tailX[i] = endX;
		tailY[i] = endY;

		endX = end2X;
		endY = end2Y;
	}

	switch (mov)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case RIGHT:
		x++;
		break;
	case LEFT:
		x--;
		break;
	default:
		break;
	}

	//if you want to collise walls uncomment this and... :)
	//if (x > width || x<0 || y>height || y < 0) {
	//	youLose = true;
	//	}

	// comment this :)))
	if (x >= width)
		x = 0;
	else if (x < 0)
		x = width - 1;

	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height - 1;

	for (int i = 0; i < tailLength; i++)
	{
		if (tailX[i]==x&&tailY[i]==y)
		{
			youLose = true;
		}
	}

	if (x == getX && y == getY) {
		score += 1;
		getX = rand() % width;
		getY = rand() % height;
		tailLength++;
	}
}


int main()
{
    Setup();
    while (!youLose)
    {
        Draw();
        Input();
        Code();
		Sleep(10);
    }
    return 0;
}


