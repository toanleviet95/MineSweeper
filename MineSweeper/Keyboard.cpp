#include <iostream>
#include <conio.h>
#include "HamHoTro.h"
using namespace std;
#define max 200

void SaveGame(int a[][max], bool b[][max], int dong, int cot, int min, float time);

void main();

// HÀM BẮT PHÍM VÀ CHỌN NƯỚC ĐI
int Keyboard(int a[][max], bool b[][max], int dong, int cot, int min, float time, int &i, int &j)
{
	char ch = _getch();
	if (ch == 13) return 1; // NÚT ENTER
	if (ch == 93) // NÚT CẮM CỜ ("]")
	{
		SetBGColor(14);
		SetColor(12);
		printf("%c", 20);
	}
	if (ch == 91) // NÚT XÓA CỜ ("[")
	{
		SetBGColor(7);
		SetColor(7);
		printf(" ");
	}
	if (ch == 32) main();
	if (ch == 115 || ch == 83){
		float t2 = GetTickCount();
		float Time = (t2 - time) / 1000;
		SaveGame(a, b, dong, cot, min, Time);
		exit(0);
	}
	if (ch == -32) // Hoac (ch==0) nhung truong hop 0 chi dung cho ban phim desktop. Dung -32 de chay ca laptop va desktop
	{
		ch = _getch();
		if (ch == 72) if (i > 0)i--; else i = dong - 1; // Len 
		if (ch == 75) if (j > 0)j--; else j = cot - 1; // Phai
		if (ch == 80) if (i <dong - 1)i++; else i = 0; // Xuong
		if (ch == 77) if (j < cot - 1)j++; else j = 0; // Trai
		gotoxy(j * 3 + 1, i * 2 + 1);
	}
	return 0;
}

