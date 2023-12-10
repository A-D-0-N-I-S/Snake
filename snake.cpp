#include <iostream>
#include <conio.h> 
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int  x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail; 
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection dir;
	void Setup()
	{
		gameOver = false;
		dir = STOP;
		x = width / 2 - 1;
		y = height / 2 - 1;
		fruitX = rand() % width;
		fruitY = rand() % height;
		score = 0;
	}