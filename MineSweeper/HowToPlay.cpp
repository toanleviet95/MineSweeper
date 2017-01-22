#include <iostream>
#include <conio.h>
#include "HamHoTro.h"
using namespace std;

void VeBang();

void main();

void TieuDeHTP(){
	SetConsoleTitle(TEXT("How To Play"));
	gotoxy(6, 1);
	SetColor(12);
	SetBGColor(15);
	cout << "KEYBOARD CONTROL";
	gotoxy(1, 1);
	SetBGColor(15);
	printf("%c", 15);
	gotoxy(26, 1);
	printf("%c", 15);
	SetColor(1);
	gotoxy(5, 3);
	cout << "Move: Arrow Buttons";
	gotoxy(5, 5);
	cout << "Choose: Press ENTER";
	gotoxy(6, 7);
	cout << "Set Flag: Press ]";
	gotoxy(5, 9);
	cout << "Delete Flag: Press [";
	gotoxy(1, 11);
	cout << "Press SPACE To Return Menu";
}

void HowToPlay(){
	clrscr();
	SetBGColor(15);
	SetColor(1);
	VeBang();
	TieuDeHTP();
	char ch = _getch();
	if (ch == 32) main();
}