#include <iostream>
#include <conio.h>

using namespace std;

const int width = 100; // Ширина игрового поля
const int height = 100; // Высота игрового поля
bool gameOver; // Переменная для выхода из игры
int x, y; // Положение змейки по Ох/Oy
int fruitX, fruitY; // Положение фрукта по Ох/Оу
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; //Кнопки
eDirection dir; // Переменная хранящая значение кнопки

void Setup()
{
	gameOver = false; // Игра начата
	dir = STOP; // Кнопка не нажата
	x = width / 2; // Начальное положение змейки по Ох
	y = height / 2; // Начальное положение змейки по Оу
	fruitX = rand() % width; // Для рандомного положения яблока по Ох
	fruitY = rand() % height; // Для рандомного положения яблока по Оу
}

void Input()
{
	if (_kbhit()) // Функция для отслуживания нажатой кнопки: Возвращает true, если нажата верная кнопка
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
			gameOver = true; // Выход при нажатии на Х
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
