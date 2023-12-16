
// подключаем библиотеки
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; // Перечисление для направления движения змейки
eDirection dira;

bool gameOver; // для завершения игры

// объявляем все функции
void Setup();
void Draw();
void Input();
void Logic_Easy();
void Logic_Hard();

// константы для размера карты
const int width = 20;
const int height = 20;

// объявляем коордианаты змеи, счет игры
int x, y, fruitX, fruitY;
int score;

// переменные для каждой части змеи
int tailx[100], taily[100];

// Количество элементов в змее
int ntail;

// Функция для настроек игры
void Setup()
{
	gameOver = false; // мы же сразу не проиграли
	dira = STOP; // змейка в начале игры не двигается

	// коордианты спавна змеи
	x = width / 2;
	y = height / 2;

	// рандомные коордианты фрукта
	fruitX = rand() % width;
	fruitY = rand() % height;

	// инициализиурем счет игры
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
	// устанавливаем изначальные движения змейки
	int prevX = tailx[0];
	int prevY = taily[0];
	int prev2X, prev2Y;
	tailx[0] = x;
	taily[0] = y;

	// описываем движение змейки
	for (int i = 1; i < ntail; i++)
	{
		prev2X = tailx[i];
		prev2Y = taily[i];
		tailx[i] = prevX;
		taily[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	// Характерезуем движение змейки
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

	// Если змейка врежется в стенку, она пойдет с другой стороны
	if (x >= width) x = 0; else if (x < 0)x = width - 1;
	if (y >= height) y = 0; else if (y < 0)y = height - 1;

	// Часть кода, которая отвечает за то, если голова и часть змеи совпадают - мы проиграли
	for (int i = 0; i < ntail; i++)
	{
		if (tailx[i] == x && taily[i] == y)
		{
			gameOver = true;
		}
	}

	// Присваевывание очков за сьедание фруктов и спавн нового
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		ntail++; // увеличиваем размер змеи
	}

}

void Logic_Hard()
{
	
}


// Все это подключаем в основную функцию
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