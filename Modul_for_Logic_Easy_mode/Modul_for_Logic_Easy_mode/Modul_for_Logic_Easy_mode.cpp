
// ���������� ����������
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; // ������������ ��� ����������� �������� ������
eDirection dira;

bool gameOver; // ��� ���������� ����

// ��������� ��� �������
void Setup();
void Draw();
void Input();
void Logic_Easy();
void Logic_Hard();

// ��������� ��� ������� �����
const int width = 20;
const int height = 20;

// ��������� ����������� ����, ���� ����
int x, y, fruitX, fruitY;
int score;

// ���������� ��� ������ ����� ����
int tailx[100], taily[100];

// ���������� ��������� � ����
int ntail;

// ������� ��� �������� ����
void Setup()
{
	gameOver = false; // �� �� ����� �� ���������
	dira = STOP; // ������ � ������ ���� �� ���������

	// ���������� ������ ����
	x = width / 2;
	y = height / 2;

	// ��������� ���������� ������
	fruitX = rand() % width;
	fruitY = rand() % height;

	// �������������� ���� ����
	score = 0;
}

void Draw()
{

}

void Input()
{

}

void Logic_Easy()
{
	// ������������� ����������� �������� ������
	int prevX = tailx[0];
	int prevY = taily[0];
	int prev2X, prev2Y;
	tailx[0] = x;
	taily[0] = y;

	// ��������� �������� ������
	for (int i = 1; i < ntail; i++)
	{
		prev2X = tailx[i];
		prev2Y = taily[i];
		tailx[i] = prevX;
		taily[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	// ������������� �������� ������
	switch (dira)
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
	default:
		break;
	}

	// ���� ������ �������� � ������, ��� ������ � ������ �������
	if (x >= width) x = 0; else if (x < 0)x = width - 1;
	if (y >= height) y = 0; else if (y < 0)y = height - 1;

	// ����� ����, ������� �������� �� ��, ���� ������ � ����� ���� ��������� - �� ���������
	for (int i = 0; i < ntail; i++)
	{
		if (tailx[i] == x && taily[i] == y)
		{
			gameOver = true;
		}
	}

	// �������������� ����� �� �������� ������� � ����� ������
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		ntail++; // ����������� ������ ����
	}

}

void Logic_Hard()
{
	
}


// ��� ��� ���������� � �������� �������
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