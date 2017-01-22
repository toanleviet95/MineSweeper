#include <iostream>
#include <conio.h>
#include "HamHoTro.h"
#include "CapDo.h"
using namespace std;
#define max 200

void main();

void XuLyLoad(FILE *&s1, FILE *&s2, void(*CapDo)(Level &L), void(*ChuThich)(int min), void(*PathTime)(FILE *&f), void(*Path)(FILE *&f1, FILE *&f2), float time);

// SAVE GAME
void SaveGame(int a[][max], bool b[][max], int dong, int cot, int min, float time){
	FILE *s1 = fopen("saveA.txt", "wt");
	FILE *s2 = fopen("saveB.txt", "wt");
	FILE *s3 = fopen("saveMin.txt", "wt");
	fprintf(s3, "%d %.2f", min, time);
	for (int i = 0; i < dong; i++){
		for (int j = 0; j < cot; j++){
			fprintf(s1, "%d ", a[i][j]);
			if (b[i][j] == true)
				fprintf(s2, "x");
			else fprintf(s2, "o");
		}
	}
	fcloseall();
}

// LOAD GAME
void LoadGame(){
	int min;
	float time;
	FILE *s1 = fopen("saveA.txt", "rt");
	FILE *s2 = fopen("saveB.txt", "rt");
	FILE *s3 = fopen("saveMin.txt", "rt");
	if (s1 == NULL || s2 == NULL || s3 == NULL){
		SetConsoleTitle(TEXT("Load Game"));
		clrscr();
		gotoxy(3, 5);
		cout << "There is no Save Data !";
		gotoxy(2, 8);
		cout << "Press SPACE To Return Menu";
		char ch = _getch();
		if (ch == 32) main();
		else exit(0);
	}
	else{
		fscanf(s3, "%d", &min);
		fscanf(s3, "%f", &time);
		if (min == 10)
			XuLyLoad(s1, s2, De, ChuThichDe, PathTimeDe, PathDe, time);
		else if (min == 40)
			XuLyLoad(s1, s2, TrungBinh, ChuThichTrungBinh, PathTimeTB, PathTB, time);
		else
			XuLyLoad(s1, s2, Kho, ChuThichKho, PathTimeKho, PathKho, time);
		fcloseall();
	}
}
