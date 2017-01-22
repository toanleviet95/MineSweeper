#include <iostream>
#include "HamHoTro.h"
#include "Struct.h"
using namespace std;

void De(Level &L){
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(TEXT("Easy [9x9]"));
	COORD bufferSize = { 29, 24 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	resizeConsole(250, 350);
	L.dong = 9;
	L.cot = 9;
	L.min = 10;
}

void TrungBinh(Level &L){
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(TEXT("Normal [16x16]"));
	COORD bufferSize = { 50, 38 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	resizeConsole(450, 500);
	L.dong = 16;
	L.cot = 16;
	L.min = 40;
}

void Kho(Level &L){
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(TEXT("Hard [16x30]"));
	COORD bufferSize = { 92, 38 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	resizeConsole(800, 500);
	L.dong = 16;
	L.cot = 30;
	L.min = 99;
}

void ChuThichDe(int min){
	SetBGColor(1);
	SetColor(14);
	gotoxy(7, 20);
	cout << (char)15 << " : " << min << " MINES ";
	SetBGColor(14);
	SetColor(12);
	gotoxy(0, 22);
	cout << (char)16 << "PRESS BUTTON S TO SAVE GAME ";
	gotoxy(9, 23);
	cout << " AND EXIT ";
}

void ChuThichTrungBinh(int min){
	SetBGColor(1);
	SetColor(14);
	gotoxy(18, 34);
	cout << (char)15 << " : " << min << " MINES ";
	SetBGColor(14);
	SetColor(12);
	gotoxy(11, 36);
	cout << (char)16 << " PRESS BUTTON S TO SAVE GAME ";
	gotoxy(20, 37);
	cout << " AND EXIT ";
}

void ChuThichKho(int min){
	SetBGColor(1);
	SetColor(14);
	gotoxy(39, 34);
	cout << (char)15 << " : " << min << " MINES";
	SetBGColor(14);
	SetColor(12);
	gotoxy(32, 36);
	cout << (char)16 << " PRESS BUTTON S TO SAVE GAME ";
	gotoxy(41, 37);
	cout << " AND EXIT ";
}

void PathDe(FILE *&f1, FILE *&f2){
	SetConsoleTitle(TEXT("Easy(9x9)"));
	f1 = fopen("TenDe.txt", "wt");
	f2 = fopen("TimeDe.txt", "wt");
}

void PathTB(FILE *&f1, FILE *&f2){
	SetConsoleTitle(TEXT("Normal(16x16)"));
	f1 = fopen("TenTB.txt", "wt");
	f2 = fopen("TimeTB.txt", "wt");
}

void PathKho(FILE *&f1, FILE *&f2){
	SetConsoleTitle(TEXT("Hard(16x30"));
	f1 = fopen("TenKho.txt", "wt");
	f2 = fopen("TimeKho.txt", "wt");
}

void PathTimeDe(FILE *&f){
	f = fopen("TimeDe.txt", "r");
}

void PathTimeTB(FILE *&f){
	f = fopen("TimeTB.txt", "r");
}

void PathTimeKho(FILE *&f){
	f = fopen("TimeKho.txt", "r");
}