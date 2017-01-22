#include <iostream>
#include "HamHoTro.h"
using namespace std;

void VeBang();

int KeyboardBang(int &i);

void NewGame();

void LoadGame();

void BestScores();

void HowToPlay();

void TieuDeMenu(){
	SetConsoleTitle(TEXT("Menu"));
	gotoxy(9, 1);
	SetColor(12);
	SetBGColor(14);
	printf("MINESWEEPER");
	gotoxy(1, 1);
	SetBGColor(14);
	printf("%c", 15);
	gotoxy(26, 1);
	printf("%c", 15);
	gotoxy(8, 3);
	SetBGColor(7);
	printf("Win32 Console");
	gotoxy(5, 5);
	SetBGColor(14);
	SetColor(1);
	printf("%c", 16);
	gotoxy(11, 5);
	SetBGColor(7);
	printf("New Game");
	gotoxy(5, 6);
	SetBGColor(14);
	printf("%c", 16);
	gotoxy(11, 6);
	SetBGColor(7);
	printf("Load Game");
	gotoxy(5, 7);
	SetBGColor(14);
	printf("%c", 16);
	gotoxy(10, 7);
	SetBGColor(7);
	printf("Best Scores");
	gotoxy(5, 8);
	SetBGColor(14);
	printf("%c", 16);
	gotoxy(10, 8);
	SetBGColor(7);
	printf("How To Play");
	gotoxy(1, 10);
	printf("Copyright %c 2014 By LVToan", 1);
	gotoxy(4, 11);
	printf("University Of Science");
}

void XuLyMenu()
{
	int i = 4;
	gotoxy(5, 5);
	do{
		int chon;
		do{
			chon = KeyboardBang(i);
		} while (chon == 0);
		if (i == 4) NewGame();
		else if (i == 5) LoadGame();
		else if (i == 6) BestScores();
		else HowToPlay();
	} while (1);
}

void main(){
	clrscr();
	SetBGColor(7);
	SetColor(1);
	VeBang();
	TieuDeMenu();
	XuLyMenu();
}




