#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

bool gameOver;

void Setup()
{
	gameOver = false;
}

void Draw()
{

}

void Input()
{

}

void Logic_Easy()
{
	
}

void Logic_Hard()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;

	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < ntail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];

		tailX[i] = prevX;
		tailY[i] = prevY;

		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x > width || x < 0 || y > height || y < 0)
	{
		system("cls");
		cout << "Game Over!\n";
		Sleep(5000);
		gameOver = true;
	}

	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[0] == y)
		{
			system("cls");
			cout << "Game Over!\n";
			Sleep(5000);
			gameOver = true;
		}
	}
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height; 
		nTail++;

	}
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic_Easy();
		Logic_Hard();
	}
	
	return 0;
}