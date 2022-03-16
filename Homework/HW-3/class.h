#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <sstream>

class TextEditor {
private:
	int len;
	std::string text;

public:
	TextEditor(short _x, short _y, int _len);
	TextEditor(const TextEditor& te);
	~TextEditor();


	friend std::ostream& operator<< (std::ostream& out, const TextEditor& te);

	void editorHide();
	void editorShow();

};

std::string editorWork(int _len, std::string _text);