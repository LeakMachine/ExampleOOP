#include "class.h"

using namespace std;

#define KEY_EXIT 27
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_ENTER 13
#define KEY_H 72
#define KEY_I 73
#define KEY_J 74
#define KEY_K 75
#define KEY_O 79

void tooltip() {
    cout << "!!USE SHIFT WHEN INPUTTING A LETTER!!\n";
    cout << "ESC - Exit the program \nH - Show tooltip \nJ - Hide editor \nK - Show editor \n";
    cout << "O - Get string you've written\n";
}

int main() {

	SetConsoleCP(1251);         
	SetConsoleOutputCP(1251);

    int iKey = 67;

    int x, y, len;

    cout << "Enter cursor coordinates (x, then y): ";
    cin >> x >> y;
    cout << "\nEnter length of string: ";
    cin >> len;

    system("CLS");

    TextEditor editor(x, y, len);

    tooltip();

    while (iKey != KEY_EXIT) {
        switch (iKey) {
            case KEY_H:
                tooltip();
                iKey = 67;
                break;
            case KEY_J:
                editor.editorHide();
                iKey = 67;
                break;
            case KEY_K:
                system("CLS");
                editor.editorShow();
                editor.editorHide();
                tooltip();
                iKey = 67;
                break;
            case KEY_O:
                cout << editor;
                iKey = 67;
                break;
            default:
                iKey = _getch();
                if (iKey == KEY_H || iKey == KEY_J || iKey == KEY_K || iKey == KEY_O || iKey == KEY_EXIT) break;
                break;
        }
    }

	return 0;
}