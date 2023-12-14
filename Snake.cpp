#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

// Перечисление для направления движения змейки
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; 
eDirection dir;

// объявлеям глобально, чтобы все функции видели эту переменную
bool gameOver; 

// объявляем все функции для игры
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


void Setup()
{
	gameOver = false; // игра не проиграна
	dir = STOP; // змейка в начале игры не двигается

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
	
}

void Logic_Hard()
{
	// устанавливаем изначальные движения змейки
	int prevX = tailX[0];
	int prevY = tailY[0];

	int prev2X, prev2Y;

	tailX[0] = x;
	tailY[0] = y;

	// описываем движение змейки
	for (int i = 1; i < ntail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];

		tailX[i] = prevX;
		tailY[i] = prevY;

		prevX = prev2X;
		prevY = prev2Y;
	}

	// характерезуем движение змейки
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

	// если змейка врежется в стенку, то мы проиграли
	if (x > width || x < 0 || y > height || y < 0)
	{
		system("cls");
		cout << "Game Over!\n";
		Sleep(5000);
		gameOver = true;
	}

	// если голова и часть змеи совпадают - мы проиграли. Вывод сообщения о проигрыше
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

	// присваивание очков за сьедание фруктов и спавн нового фрукта
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