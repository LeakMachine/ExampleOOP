#include "class.h"

#define KEY_EXIT 27
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_ENTER 13
#define KEY_BACKSPACE 8
#define KEY_H 72

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPos;
DWORD cWrittenChars;    
CONSOLE_SCREEN_BUFFER_INFO cbsi;

int iKey = 67;

TextEditor::TextEditor(short _x, short _y, int _len)
{
    int i = 0;
	len = _len;
    cursorPos = { _x,_y };
    for (int i = 0; i < len; i++) {
        text = text + '_';
    }
}

TextEditor::TextEditor(const TextEditor& te)
{
    len = te.len;
    text = te.text;
}

TextEditor::~TextEditor()
{
	if (this) {
        len = 0;
        text = "";
	}
}

void TextEditor::editorHide()
{
    system("CLS");
}

void TextEditor::editorShow()
{
    std::cout << "\nEnter your string.\nPress Enter to exit.\n";
    char chTemp;
    int i = 0;

    int tempCoordX = cursorPos.X;

    SetConsoleCursorPosition(hStdOut, cursorPos);
    for (int i = 0; i < len; i++) {
        chTemp = text[i];
        FillConsoleOutputCharacter(hStdOut, (TCHAR)chTemp, 1, cursorPos, &cWrittenChars);
        cursorPos.X++;
    }

    cursorPos.X = tempCoordX;

    SetConsoleCursorPosition(hStdOut, cursorPos);
    text = editorWork(len, text);
}

std::string editorWork(int _len, std::string _text)
{
    int lenbs = 0;
    int len = _len - 1;

    std::string text = _text;
    iKey = 67;

    int tempCoordX = cursorPos.X;

    while (iKey != KEY_ENTER) {
        switch (iKey)
        {
        case KEY_ARROW_LEFT:
            GetConsoleScreenBufferInfo(hStdOut, &cbsi);
            cursorPos.X = cbsi.dwCursorPosition.X - 1;
            SetConsoleCursorPosition(hStdOut, cursorPos);
            len++;
            lenbs--;
            iKey = 67;
            break;
        case KEY_ARROW_RIGHT:
            GetConsoleScreenBufferInfo(hStdOut, &cbsi);
            cursorPos.X = cbsi.dwCursorPosition.X + 1;
            SetConsoleCursorPosition(hStdOut, cursorPos);
            len--;
            lenbs++;
            iKey = 67;
            break;
        default:
            if (len < 0) {
                GetConsoleScreenBufferInfo(hStdOut, &cbsi);
                cursorPos.X = cbsi.dwCursorPosition.X - 1;
                SetConsoleCursorPosition(hStdOut, cursorPos);
                len++;
                lenbs--;
                break;
            }
            iKey = _getch();
            if (iKey == KEY_ENTER || iKey == ARROW_KEY || iKey == KEY_SPACE
                || iKey == KEY_ARROW_LEFT || iKey == KEY_ARROW_RIGHT || iKey == KEY_BACKSPACE) break;
            std::cout << (char)iKey;
            text = text.replace(lenbs, 1, 1, (char)iKey);
            len--;
            lenbs++;
            break;
        }
    }

    cursorPos.X = tempCoordX;

    return text;
}



std::ostream& operator<< (std::ostream& out, const TextEditor& te) {

    out << '\n' << te.text;

    return out;
}
