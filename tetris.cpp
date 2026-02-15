#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

const int width = 20;
const int height = 20;

int x = width / 2;
int y = 0;
int score = 0;
bool gameOver = false;

void draw() {
    system("cls");

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << "O";
            else
                cout << " ";

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";

    cout << "\nScore: " << score;
}

void input() {

    if (_kbhit()) {

        switch (_getch()) {

        case 'a':
            x--;
            break;

        case 'd':
            x++;
            break;

        case 's':
            y++;
            break;

        case 'x':
            gameOver = true;
            break;
        }
    }
}

void logic() {

    y++;
    Sleep(200);

    if (y > height - 1) {
        y = 0;
        score++;
    }

    if (x < 0) x = 0;
    if (x > width - 1) x = width - 1;
}

int main() {

    while (!gameOver) {

        draw();
        input();
        logic();
    }

    cout << "\nGame Over!";
    return 0;
}
