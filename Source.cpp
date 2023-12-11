#include <iostream>
#include <ctime>
using namespace std;

const int width = 200;       // Ширина игрового поля
const int height = 30;      // Высота игрового поля
int x, y, fruitX, fruitY;   // Координаты змейки (x, y) и фрукта (fruitX, fruitY)

void Setup() {
    x = width / 2 - 1;      // Начальная позиция змейки по горизонтали
    y = height / 2 - 1;     // Начальная позиция змейки по вертикали
    srand(time(0));         // Инициализация генератора случайных чисел с использованием текущего времени
    fruitX = rand() % width;  // Генерация случайной позиции фрукта по горизонтали
    fruitY = rand() % height; // Генерация случайной позиции фрукта по вертикали
}

void Draw() {
    system("cls");          // Очистка экрана консоли

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
            else if (i == y && j == x)
                cout << "0";
            // Если это позиция фрукта, выводим "F"
            else if (i == fruitY && j == fruitX)
                cout << "*";
            // В остальных случаях выводим пустое пространство
            else
                cout << " ";
        }
        cout << endl;
    }

    // Вывод нижней границы
    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;
}

int main() {
    Setup();  // Инициализация начальных параметров
    Draw();   // Вывод игрового поля

    return 0;  // Завершение программы
}
