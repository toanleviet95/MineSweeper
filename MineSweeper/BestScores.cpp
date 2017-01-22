#include <iostream>
#include <conio.h>
#include "HamHoTro.h" 
using namespace std;

void VeBang();

void NhacWIN();

void main();

void TieuDeBangTen(float time)
{
	gotoxy(5, 1);
	printf("FASTEST MINESWEEPER");
	gotoxy(1, 1);
	printf("%c", 15);
	gotoxy(26, 1);
	printf("%c", 15);
	gotoxy(1, 5);
	printf("NAME:");
	gotoxy(1, 6);
	printf("<Limited to 10 characters>");
	gotoxy(1, 9);
	printf("BEST TIME:");
	gotoxy(12, 9);
	printf("%.2f s", time);
}

void BangTen(float time, FILE *&f1, FILE *&f2){
	char ten[11];
	VeBang();
	TieuDeBangTen(time);
	gotoxy(7, 5);
	FILE* _stream;
	fgets(ten, 50, _stream);
	if (f1 != NULL && f2 != NULL)
	{
		fputs(ten, f1);
		fprintf(f2, "%.2f", time);
		fcloseall();
	}
	exit(0);
}

void TieuDeScore()
{
	SetConsoleTitle(TEXT("Best Scores"));
	gotoxy(9, 1);
	printf("BEST PLAYERS");
	gotoxy(1, 1);
	printf("%c", 15);
	gotoxy(26, 1);
	printf("%c", 15);
	gotoxy(1, 3);
	printf("Easy:");
	gotoxy(1, 5);
	printf("Normal:");
	gotoxy(1, 7);
	printf("Hard:");
	gotoxy(1, 9);
	printf("Press SPACE To Return Menu");
}

void XuatScore()
{
	char ten1[11];
	char ten2[11];
	char ten3[11];
	float t1, t2, t3;
	FILE *f1 = fopen("TenDe.txt", "rt");
	FILE *f2 = fopen("TimeDe.txt", "rt");
	FILE *f3 = fopen("TenTB.txt", "rt");
	FILE *f4 = fopen("TimeTB.txt", "rt");
	FILE *f5 = fopen("TenKho.txt", "rt");
	FILE *f6 = fopen("TimeKho.txt", "rt");
	if (f1 == NULL || f2 == NULL) // Nếu không tìm thấy vì chưa chơi thắng
	{
		gotoxy(9, 3);
		printf("None"); // in ra vô danh vì chưa chơi thắng 
	}
	else
	{
		fgets(ten1, 10, f1);
		fscanf(f2, "%f", &t1);
		gotoxy(9, 3);
		printf("%s[%.2f]", ten1, t1);
		fcloseall();
	}
	if (f3 == NULL || f4 == NULL)
	{
		gotoxy(9, 5);
		printf("None");
	}
	else
	{
		fgets(ten2, 10, f3);
		fscanf(f4, "%f", &t2);
		gotoxy(9, 5);
		printf("%s[%.2f]", ten2, t2);
		fcloseall();
	}
	if (f5 == NULL || f6 == NULL)
	{
		gotoxy(9, 7);
		printf("None");
	}
	else
	{
		fgets(ten3, 10, f5);
		fscanf(f6, "%f", &t3);
		gotoxy(9, 7);
		printf("%s[%.2f]", ten3, t3);
		fcloseall();
	}
}

void BestScores(){
	clrscr();
	SetBGColor(1);
	SetColor(14);
	VeBang();
	TieuDeScore();
	XuatScore();
	NhacWIN();
	char ch = _getch();
	if (ch == 32) main();
	else exit(0);
}


