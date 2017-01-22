#include <iostream>
#include "HamHoTro.h"
#include "CapDo.h"

void VeBang();

int KeyboardBang(int &i);

void XuLyGame(void(*CapDo)(Level &L), void(*ChuThich)(int min), void(*PathTime)(FILE *&f), void(*Path)(FILE *&f1, FILE *&f2));

void main();

void TieuDeNewGame(){
	SetConsoleTitle(TEXT("New Game"));
	gotoxy(12, 1);
	SetColor(1);
	printf("LEVEL");
	gotoxy(1, 1);
	printf("%c", 15);
	gotoxy(26, 1);
	printf("%c", 15);
	gotoxy(5, 5);
	SetBGColor(15);
	SetColor(1);
	printf("%c", 16);
	gotoxy(12, 5);
	SetBGColor(14);
	SetColor(1);
	printf("Easy");
	gotoxy(5, 6);
	SetBGColor(15);
	SetColor(12);
	printf("%c", 16);
	gotoxy(12, 6);
	SetBGColor(14);
	SetColor(12);
	printf("Normal");
	gotoxy(5, 7);
	SetBGColor(15);
	SetColor(6);
	printf("%c", 16);
	gotoxy(12, 7);
	SetBGColor(14);
	SetColor(6);
	printf("Hard");
	gotoxy(5, 8);
	SetBGColor(15);
	SetColor(0);
	printf("%c", 16);
	gotoxy(8, 8);
	SetBGColor(14);
	SetColor(0);
	printf("Return To Menu");
}

void XuLyNewGame()
{
	int i = 4;
	gotoxy(5, 5);
	do{
		int chon;
		do{
			chon = KeyboardBang(i);
		} while (chon == 0);
		if (i == 4)
		{
			XuLyGame(De, ChuThichDe, PathTimeDe, PathDe); // Mức Dễ 
		}
		else if (i == 5)
		{
			XuLyGame(TrungBinh, ChuThichTrungBinh, PathTimeTB, PathTB); // Mức Trung
		}
		else if (i == 6)
		{
			XuLyGame(Kho, ChuThichKho, PathTimeKho, PathKho); // Mức Khó
		}
		else main();
	} while (1);
}

void NewGame(){
	clrscr();
	SetBGColor(14);
	SetColor(12);
	VeBang();
	TieuDeNewGame();
	XuLyNewGame();
}