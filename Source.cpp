#include <iostream>
#include <ctime>
using namespace std;

const int width = 200;       // ������ �������� ����
const int height = 30;      // ������ �������� ����
int x, y, fruitX, fruitY;   // ���������� ������ (x, y) � ������ (fruitX, fruitY)

void Setup() {
    x = width / 2 - 1;      // ��������� ������� ������ �� �����������
    y = height / 2 - 1;     // ��������� ������� ������ �� ���������
    srand(time(0));         // ������������� ���������� ��������� ����� � �������������� �������� �������
    fruitX = rand() % width;  // ��������� ��������� ������� ������ �� �����������
    fruitY = rand() % height; // ��������� ��������� ������� ������ �� ���������
}

void Draw() {
    system("cls");          // ������� ������ �������

    // ����� ������� �������
    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;

    // ����� �������� ����
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // ���� ��� ����, �� ������� �������
            if (j == 0 || j == width - 1)
                cout << "#";
            // ���� ��� ������� ������� ������, ������� "0"
            else if (i == y && j == x)
                cout << "0";
            // ���� ��� ������� ������, ������� "F"
            else if (i == fruitY && j == fruitX)
                cout << "*";
            // � ��������� ������� ������� ������ ������������
            else
                cout << " ";
        }
        cout << endl;
    }

    // ����� ������ �������
    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;
}

int main() {
    Setup();  // ������������� ��������� ����������
    Draw();   // ����� �������� ����

    return 0;  // ���������� ���������
}
