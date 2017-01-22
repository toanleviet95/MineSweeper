#include <iostream>
#include <conio.h>
#include "Struct.h"
#include "HamHoTro.h"
#include "XuLy.h"
using namespace std;

void main();

void XuLy(Level L, void(*PathTime)(FILE *&f), void(*Path)(FILE *&f1, FILE *&f2), float time)
{
	int i = 0, j = 0; 
	gotoxy(j * 3 + 1, i * 2 + 1);
	float t1 = GetTickCount(); // Đặt t1 là thời điểm mới bắt đầu game
	do{
		int chon;
		do{
			chon = Keyboard(L.a, L.b, L.dong, L.cot, L.min, t1, i, j);
		} while (chon == 0);
		if (L.a[i][j] == -1)
		{
			XuatMin(L.a, L.dong, L.cot);
			GAMEOVER();
			exit(0);
		}
		else
		{
			if (L.a[i][j] == 0) // Nếu là ô không có bom thì mở lan ra
			{
				MoOkhong(L.a, i, j, L.dong, L.cot, L.b);
				XuLyXungQuanh(L.a, i, j, L.dong, L.cot, L.b);
				coin();
			}
			else
				MoOso(L.a, i, j, L.b);	// Còn lại thì mở bình thường 
		}
		if (ChuaMo(L.b, L.dong, L.cot) == L.min) // Nếu đếm số ô còn lại chưa mở khớp với số bom thì THẮNG
		{
			FILE *f;
			FILE *f1;
			FILE *f2;
			float t2 = GetTickCount(); // Đặt thời điểm t2 khi thắng
			float nowTime = ((t2 - t1) / 1000) + time; // t2-t1 ra khoảng thời gian chơi, chia cho 1000 vì GetTickCount lấy đơn vị là ms
			WIN();
			gotoxy(32, 30);
			printf("YOUR TIME: %.2f seconds", nowTime);
			_getch();
			PathTime(f);
			if (f == NULL){
				Path(f1, f2);
				BangTen(nowTime, f1, f2); // Nếu tìm không thấy thì cho nhập tên, rồi lưu tên và thời gian vào file
			}
			else // Nếu tìm thấy thì đọc dữ liệu thời gian từ file đã lưu và đem so sánh với thời gian hiện tại
			{
				float pastTime;
				fscanf(f, "%f", &pastTime);
				if (nowTime < pastTime) // Nếu thời gian hiện tại phá kỉ lục của người chơi trước thì lấy thời gian hiện tại
				{
					fclose(f);
					gotoxy(32, 32);
					printf("CONGRATULATION !");
					gotoxy(25, 34);
					printf("YOU BEAT %.2f seconds TO BE THE FASTEST MINESWEEPER !", pastTime);
					_getch();
					Path(f1, f2);
					BangTen(nowTime, f1, f2);
				}
				else {
					fclose(f);
					gotoxy(25, 32);
					cout << "TRY MORE TO BE THE FASTEST MINESWEEPER";
				}
			}
			exit(0);
		}
	} while (1);
}

void XuLyGame(void(*CapDo)(Level &L), void(*ChuThich)(int min), void(*PathTime)(FILE *&f), void(*Path)(FILE *&f1, FILE *&f2)){
	Level L;
	CapDo(L);
	VeBanCo(L.dong, L.cot);
	ChuThich(L.min);
	PhatSinhMin(L.a, L.dong, L.cot, L.min, L.b);
	TaoBaiMin(L.a, L.dong, L.cot);
	XuLy(L, PathTime, Path, 0);
}

void XuLyLoad(FILE *&s1, FILE *&s2, void(*CapDo)(Level &L), void(*ChuThich)(int min), void(*PathTime)(FILE *&f), void(*Path)(FILE *&f1, FILE *&f2), float time){
	Level L;
	CapDo(L);
	VeBanCo(L.dong, L.cot);
	ChuThich(L.min);
	for (int i = 0; i < L.dong; i++)
	for (int j = 0; j < L.cot; j++){
		fscanf(s1, "%d", &L.a[i][j]);
		fscanf(s2, "%c", &L.b[i][j]);
	}
	for (int i = 0; i < L.dong; i++)
	for (int j = 0; j < L.cot; j++)
	if (L.b[i][j] == 'x')
		MoOso(L.a, i, j, L.b);
	else L.b[i][j] = false;
	XuLy(L, PathTime, Path, time);
}


