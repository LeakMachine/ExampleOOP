#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define KEY_EXIT 27
#define ARROW_KEY 224
#define KEY_SPACE 0

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75

#define KEY_PAGE_UP 73
#define KEY_PAGE_DOWN 81

#define KEY_ENTER 13

using namespace std;

int main() {

	system("title Game");

	int exitClrPick = 0;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	while (exitClrPick == 0) {

		char clrinput;

		cout << "Select text color (w / g), 'e' to exit: ";

		cin >> clrinput;

		switch (clrinput) {
		case 'w':
			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);  std::cout << "test" << std::endl;
			break;
		case 'g':
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);  std::cout << "test" << std::endl;
			break;
		case 'e':
			exitClrPick = 1;
			break;
		default:
			cout << "invalid input" << endl;
			break;
		}
	}

	system("CLS");

    int iKey = 67;              // просто заглушка
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    COORD cursorPos;

	int progMode = 1;

	cout << "<< PLAY >>" << endl;
	cout << "  EXIT  " << endl;

    while (iKey != KEY_EXIT) {
        switch (iKey)
        {
        case KEY_PAGE_UP:
            GetConsoleScreenBufferInfo(hStdOut, &cbsi);   
			system("CLS");
			cout << "<< PLAY >>" << endl;
			cout << "  EXIT  " << endl;
			progMode = 1;
            iKey = 67;
            break;
        case KEY_PAGE_DOWN:
            GetConsoleScreenBufferInfo(hStdOut, &cbsi);
			system("CLS");
			cout << "  PLAY  " << endl;
			cout << "<< EXIT >>" << endl;
			progMode = 0;
            iKey = 67;
            break;
		case KEY_ENTER:
			GetConsoleScreenBufferInfo(hStdOut, &cbsi);
			if (progMode) {
                system("CLS");
				iKey = 27;
			}
			if (progMode == 0) {
                system("CLS");
				return 0;
			}

			break;
        default:
            iKey = _getch();
            break;
        }
    }

    int len = 3;
    iKey = 67;

    while (iKey != KEY_EXIT && len > 0) {
        switch (iKey)
        {
        case KEY_ARROW_LEFT:
            GetConsoleScreenBufferInfo(hStdOut, &cbsi);       // извлекает информацию о заданном экранном буфере консоли
            cursorPos.X = cbsi.dwCursorPosition.X - 1;        // смещаем текущее положение курсора на символ назад
            SetConsoleCursorPosition(hStdOut, cursorPos);
            len++;
            iKey = 67;
            break;
        case KEY_ARROW_RIGHT:
            GetConsoleScreenBufferInfo(hStdOut, &cbsi);
            cursorPos.X = cbsi.dwCursorPosition.X + 1;
            SetConsoleCursorPosition(hStdOut, cursorPos);
            len--;
            iKey = 67;
            break;
        default:
            iKey = _getch();
            if (iKey == KEY_EXIT || iKey == ARROW_KEY || iKey == KEY_SPACE
                || iKey == KEY_ARROW_LEFT || iKey == KEY_ARROW_RIGHT) break;
            std::cout << (char)iKey;    // только если это символ текста отображаем его в консоль
            len--;
            break;
        }
    }

    wchar_t Input[4];
    DWORD dwRead;
    ReadConsoleOutputCharacter(hStdOut, Input, 4, { 5, 5 }, & dwRead);
    Input[3] = '\0';




	return 0;
}