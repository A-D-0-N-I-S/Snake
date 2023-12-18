#include <iostream>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

using namespace std;


//выбор сложности игры
int selection;

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

// Перечисление для направления движения змейки
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

// переменные для каждой части змеи
int tailX[100], tailY[100];

// Количество элементов в змее
int nTail;

void SoundСollect(const char* filename)
{
	PlaySound(TEXT("24.wav"), NULL, SND_FILENAME | SND_ASYNC);
}


void Setup()
{
	setlocale(LC_ALL, "Russian");

	gameOver = false; // игра не проиграна
	dir = STOP; // змейка в начале игры не двигается

	// коордианты спавна змеи
	x = width / 2 - 1;
	y = height / 2 - 1;

	// рандомные коордианты фрукта
	fruitX = rand() % width;
	fruitY = rand() % height;

	// инициализиурем счет игры
	score = 0;
	cout << "Выберите сложность игры (1 - лёгкий, 2 - сложный): ";
	cin >> selection;

	PlaySound(TEXT("okey-lets-gou-lets-go.wav"), NULL, SND_FILENAME | SND_ASYNC);
}



void Draw()
{
	Sleep(200); // ожидание
	system("cls");    // Очистка экрана консоли
	
	// Вывод верхней границы
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;

	// Вывод игрового поля
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// Если это край, то выводим границу
			if (j == 0 || j == width - 1)
				cout << "#";
			// Если это текущая позиция змейки, выводим "0"
			if (i == y && j == x)
				cout << "0";
			// Если это позиция фрукта, выводим "F"
			else if (i == fruitY && j == fruitX)
				cout << "F";
			// В остальных случаях выводим пустое пространство
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						print = true;
						cout << "o";
					}
				}
				if (!print)
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}

	// Вывод нижней границы
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
	cout << "Score: " << score << '\n';
}

void Input()
{
	if (_kbhit()) // Функция для отслеживания нажатой кнопки: Возвращает true, если нажата верная кнопка
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true; // Выход при нажатии на Х
			break;
		}
	}
}

void Logic_Easy()
{
	if (selection == 1)
	{
		// устанавливаем изначальные движения змейки
		int prevX = tailX[0];
		int prevY = tailY[0];
		int prev2X, prev2Y;
		tailX[0] = x;
		tailY[0] = y;

		// описываем движение змейки
		for (int i = 1; i < nTail; i++)
		{
			prev2X = tailX[i];
			prev2Y = tailY[i];
			tailX[i] = prevX;
			tailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}

		// Характерезуем движение змейки
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

		// Если змейка врежется в стенку, она пойдет с другой стороны
		if (x >= width)
			x = 0;
		else if (x < 0)
			x = width - 1;
		if (y >= height)
			y = 0;
		else if (y < 0)
			y = height - 1;

		// Часть кода, которая отвечает за то, если голова и часть змеи совпадают - мы проиграли
		for (int i = 0; i < nTail; i++)
		{
			if (tailX[i] == x && tailY[i] == y)
			{
				system("cls");
				Sleep(100);
				cout << "Game Over!\n";
				PlaySound(TEXT("oh.wav"), NULL, SND_FILENAME | SND_ASYNC);
				gameOver = true;
				
			}
		}

		// Присваевывание очков за съедание фруктов и спавн нового
		if (x == fruitX && y == fruitY)
		{
			score += 10;
			fruitX = rand() % width;
			fruitY = rand() % height;
			nTail++; // увеличиваем размер змеи
			
			SoundСollect("24.wav");  //вызов звука
		}
	}
}

void Logic_Hard()
{
	if (selection == 2)
	{
		// устанавливаем изначальные движения змейки
		int prevX = tailX[0];
		int prevY = tailY[0];

		int prev2X, prev2Y;

		tailX[0] = x;
		tailY[0] = y;

		// описываем движение змейки
		for (int i = 1; i < nTail; i++)
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
			Sleep(100);
			cout << "Game Over!\n";
			PlaySound(TEXT("oh.wav"), NULL, SND_FILENAME | SND_ASYNC);
			gameOver = true;
			
		}

		// если голова и часть змеи совпадают - мы проиграли. Вывод сообщения о проигрыше
		for (int i = 0; i < nTail; i++)
		{
			if (tailX[i] == x && tailY[0] == y)
			{
				system("cls");
				cout << "Game Over!\n";
				PlaySound(TEXT("oh.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
			SoundСollect("24.wav");

		}
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
	system("pause");
	return 0;
}