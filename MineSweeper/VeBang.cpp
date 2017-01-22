#include <iostream>
#include <conio.h>
#include "HamHoTro.h"
using namespace std;

void VeBang()
{
	char vuongTraiTren = 218;
	char vuongTraiDuoi = 192;
	char vuongPhaiTren = 191;
	char vuongPhaiDuoi = 217;
	char ngang = 196;
	char doc = 179;
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = { 0, 0, 28, 12 };
	COORD bufferSize = { 29, 13 };
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	cout << vuongTraiTren;
	for (int i = 1; i < 27; i++)
		cout << ngang;
	cout << vuongPhaiTren;
	cout << endl;
	cout << doc;
	for (int i = 1; i < 27; i++)
		printf(" ");
	cout << doc;
	cout << endl;
	cout << doc;
	for (int i = 1; i < 27; i++)
		cout << (char)42;
	cout << doc;
	cout << endl;
	for (int i = 0; i<9; i++)
	{
		cout << doc;
		for (int i = 1; i < 27; i++)
			printf(" ");
		cout << doc;
		cout << endl;
	}
	cout << vuongTraiDuoi;
	for (int i = 1; i < 27; i++)
		cout << ngang;
	cout << vuongPhaiDuoi;
}

int KeyboardBang(int &i)
{
	char ch = _getch();
	if (ch == 27) exit(0); // NÚT ESC
	if (ch == 13) return 1; // NÚT ENTER
	if (ch == -32)
	{
		ch = _getch();
		if (ch == 80) if (i < 7)i++; else i = 4; // Xuong
		if (ch == 72) if (i > 4)i--; else i = 7; // Len 
		gotoxy(5, i + 1);
	}
	return 0;
}

