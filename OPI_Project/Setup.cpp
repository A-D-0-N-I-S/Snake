#include <iostream>
#include <conio.h>

using namespace std;

const int width = 100; // ������ �������� ����
const int height = 100; // ������ �������� ����
bool gameOver; // ���������� ��� ������ �� ����
int x, y; // ��������� ������ �� ��/Oy
int fruitX, fruitY; // ��������� ������ �� ��/��
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; //������
eDirection dir; // ���������� �������� �������� ������

void Setup()
{
	gameOver = false; // ���� ������
	dir = STOP; // ������ �� ������
	x = width / 2; // ��������� ��������� ������ �� ��
	y = height / 2; // ��������� ��������� ������ �� ��
	fruitX = rand() % width; // ��� ���������� ��������� ������ �� ��
	fruitY = rand() % height; // ��� ���������� ��������� ������ �� ��
}

void Input()
{
	if (_kbhit()) // ������� ��� ������������ ������� ������: ���������� true, ���� ������ ������ ������
	{
		switch (_getch())
		{
		case'a':
			dir = LEFT;
			break;
		case'd':
			dir = RIGHT;
			break;
		case'w':
			dir = UP;
			break;
		case's':
			dir = DOWN;
			break;
		case'x':
			gameOver = true; // ����� ��� ������� �� �
			break;
		}
	}
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Input();
	}

	return 0;
}
